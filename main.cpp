/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

DigitalIn button(D6);

int main()
{
    while(1){
        if(button){
            printf("Button Pressed\n\r");
            wait(0.7); // simple debouncing
        }           
    }

}
