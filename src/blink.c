#include <stdio.h>
#include "pico/stdlib.h"
#include <hardware/gpio.h>
#include <hardware/adc.h>
#include <pico/binary_info.h>
#include <sys/types.h>

#include "qwiic_led_stick.h"

int main() {
	const uint LED_PIN = 25;
	const uint OTHER_LED_PIN = 16;
	gpio_init(LED_PIN);
	gpio_init(OTHER_LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);
	gpio_set_dir(OTHER_LED_PIN, GPIO_OUT);
	stdio_init_all();

    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);

    adc_init();
    adc_gpio_init(26);

    uint loops = 0;
    uint buf;
    u_int8_t c[20];

    u_int8_t red, green, blue;

    u_int16_t adc_result;

    printf("Hello World!\n");
	while (true) {
		green = 255;
		red = 0;
		blue = 127;
		for (int i=1; i<=10; i++) {
			gpio_put(LED_PIN, 1);
			gpio_put(OTHER_LED_PIN, 0);
			sleep_ms(i*50);
			gpio_put(LED_PIN, 0);
			gpio_put(OTHER_LED_PIN, 1);

            qwiic_write_all_color(red, green, blue);
            red += i;
            blue -=i;
			sleep_ms(500);

			if (buf = uart_is_readable(uart0)) {
			    printf("UART is readable, %d in queue:\t", buf);
			    uart_read_blocking(uart0, c, 1);
			    printf("%c\r\n", c[0]);
            }
		}
	    printf("loops:\t%d  ", loops);
	    printf("\r\n");
	    loops++;

	    adc_select_input(0);
	    adc_result = adc_read();


	    printf("raw: %d\r\n", adc_result);

	}
}
