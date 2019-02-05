/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
Serial pc(USBTX, USBRX);
Thread thread;

void thread2(){
    while(1){
        pc.printf("thread2 thread\r\n");
        led2 = !led2;
        wait(0.5);
    }
}
int main(){
    thread.start(thread2);

    while(1){
        pc.printf("main thread\r\n");
        led1 = !led1;
        wait(0.5);
    }
    
}