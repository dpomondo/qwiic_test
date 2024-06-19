#ifndef _QWIIC_STICK_H_
#define _QWIIC_STICK_H_

/* driving a Sparkfun Qwiic LED Stick va i2c
 * */

#include <sys/types.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#define QWIIC_ADDRESS_DEFAULT 0x23
#define QWIIC_ADDRESS_JUMPER 0x22

#define QWIIC_COM_ADDRESS_CHANGE        0xC7
#define QWIIC_COM_CHANGE_LED_LENGTH     0x70
#define QWIIC_WRITE_SINGLE_LED_COLOR    0x71
#define QWIIC_WRITE_ALL_LED_COLOR       0x72
#define QWIIC_WRITE_RED_ARRAY           0x73
#define QWIIC_WRITE_GREEN_ARRAY         0x74
#define QWIIC_WRITE_BLUE_ARRAY          0x75
#define QWIIC_WRITE_SINGLE_LED_BRIGHTNESS     0x76
#define QWIIC_WRITE_ALL_LED_BRIGHTNESS        0x77
#define QWIIC_WRITE_ALL_LED_OFF         0x78 

#define QWIIC_LED_LENGTH                10
#define QWIIC_LED_LENGTH_MAX            90

extern void qwiic_write_all_color(u_int8_t red, u_int8_t green, u_int8_t blue);

/* <led> must be between (inclusive) 1 and QWIIC_LED_LENGTH_MAX
 * */
extern void qwiic_write_single_color(u_int8_t led, u_int8_t red, u_int8_t green, u_int8_t blue);

/* <led> must be between (inclusive) 1 and QWIIC_LED_LENGTH_MAX
 * <bright> only takes 2^5 values -- or between 0 and 31
 * */
extern void qwiic_write_sinlge_bright(u_int8_t led, u_int8_t bright);

/* <bright> only takes 2^5 values -- or between 0 and 31
 * */
extern void qwiic_write_all_bright(u_int8_t bright);

#endif // !QWIIC_STICK_H
