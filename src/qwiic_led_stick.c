#include <sys/types.h>
#include "qwiic_led_stick.h"
#include "hardware/i2c.h"

void qwiic_write_all_color(u_int8_t red, u_int8_t green, u_int8_t blue) {
    u_int8_t data[4];

    data[0] = QWIIC_WRITE_ALL_LED_COLOR;
    data[1] = red;
    data[2] = green;
    data[3] = blue;

    i2c_write_timeout_us(i2c0, QWIIC_ADDRESS_DEFAULT, &data, 4, false, 300);
}

/* <led> must be between (inclusive) 1 and QWIIC_LED_LENGTH_MAX
 * */
void qwiic_write_single_color(u_int8_t led, u_int8_t red, u_int8_t green, u_int8_t blue) {
    u_int8_t data[5];

    data[0] = QWIIC_WRITE_SINGLE_LED_COLOR;
    data[1] = led;
    data[2] = red;
    data[3] = green;
    data[4] = blue;

    i2c_write_timeout_us(i2c0, QWIIC_ADDRESS_DEFAULT, &data, 5, false, 300);
}

/* <led> must be between (inclusive) 1 and QWIIC_LED_LENGTH_MAX
 * <bright> only takes 2^5 values -- or between 0 and 31
 * */
void qwiic_write_sinlge_bright(u_int8_t led, u_int8_t bright) {
    u_int8_t data [3];

    data[0] = QWIIC_WRITE_SINGLE_LED_BRIGHTNESS;
    data[1] = led;
    data[2] = bright;

    i2c_write_timeout_us(i2c0, QWIIC_ADDRESS_DEFAULT, &data, 3, false, 300);
}

/* <bright> only takes 2^5 values -- or between 0 and 31
 * */
void qwiic_write_all_bright(u_int8_t bright) {
    u_int8_t data[2];

    data[0] = QWIIC_WRITE_ALL_LED_BRIGHTNESS;
    data[1] = bright;
    i2c_write_timeout_us(i2c0, QWIIC_ADDRESS_DEFAULT, &data, 2, false, 300);
}

