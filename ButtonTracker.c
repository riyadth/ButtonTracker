/**
 * Copyright (c) 2022 Riyadth Al-Kazily (riyadth@gmail.com)
 *
 * Test code for GPIO access
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#endif

#define BUTTON_GPIO (15)
#define LED_GPIO (PICO_DEFAULT_LED_PIN)

int main()
{
    bool last_button_state;
    bool button_state;
    stdio_init_all();

    // Set LED as output
    gpio_init(LED_GPIO);
    gpio_set_dir(LED_GPIO, GPIO_OUT);

    // Set button as input with pull-up
    gpio_init(BUTTON_GPIO);
    gpio_set_dir(BUTTON_GPIO, GPIO_IN);
    gpio_pull_up(BUTTON_GPIO);
    last_button_state = gpio_get(BUTTON_GPIO);

    puts("Hello, world!");

    while (1) {
        button_state = gpio_get(BUTTON_GPIO);
        if (button_state != last_button_state) {
            printf("Button %s\n", button_state ? "released" : "pressed" );
            gpio_put(LED_GPIO, button_state);
            last_button_state = button_state;
        }
    }

    return 0;
}
