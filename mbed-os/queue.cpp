/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

Serial pc(USBTX, USBRX);

Queue<uint32_t, 8> queue;
Thread thread;

void send_thread(void){
    uint32_t i = 0;
    while(1){
        queue.put(&i);
        i++;
        wait(1);
    }
}
int main(){
    thread.start(callback(send_thread));
    while(1){
        osEvent evt = queue.get();

        if(evt.status == osEventMessage){
            int message = *(int*)evt.value.p;
            printf("get Message: %d\r\n", message);
        }
    }
}