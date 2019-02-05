/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

DigitalIn mypin(D3);
DigitalOut myled(D2);

int main(){
    if(mypin.is_connected()){
        printf("mypin is connected and initialized! \n\r");
    }
    mypin.mode(PullUp);
    while(1){
        printf("mypin has value : %d \n\r", mypin.read());
        myled = !mypin;
        wait(0.25);
    }

}