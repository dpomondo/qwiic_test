cmake_minimum_required(VERSION 3.16)
include(pico_sdk_import.cmake)

project(blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(blink
	src/blink.c
	src/qwiic_led_stick.c
	)

target_link_libraries(blink 
    hardware_adc
    hardware_i2c
    pico_stdlib)

pico_add_extra_outputs(blink)
