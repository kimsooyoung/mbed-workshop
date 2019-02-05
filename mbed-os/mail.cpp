/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

Serial pc(USBTX, USBRX);

typedef struct {
    float voltage;
    float current;
    uint32_t counter;
}message_t;

Mail<message_t, 16> mail;
Thread thread;

void send_thread(void){
    uint32_t i = 0;
    while(1){
        i++;
        message_t *message = mpool.alloc();
        message->voltage = (i * 0.1) * 33;
        message->current = (i * 0.1) * 11;
        message->counter = i;
        mail.put(message);
        wait(1);
    }
}

int main(void){
    thread.start(callback(send_thread));
    while(1){
        osEvent evt = queue.get();
        if(evt.status == osEventMail){
            message_t *message = (message_t*)evt.value.p;
            pc.printf("\nVoltage: %.2f V\n\r", message->voltage);
            pc.printf("Current: %.2f A\n\r", message->current);
            pc.printf("Number of cycles : %d\r\n", message->counter);

            mail.free(message);
        }
    }
}