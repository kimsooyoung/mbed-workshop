/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

Serial pc(USBTX, USBRX);

Semaphore stdio_sema(2);
Thread t2;
Thread t3;

void notify(const char *name, int state){
    stdio_sema.wait();
    pc.printf("%s : %d this is for test try this!\n\r", name, state);
    wait(1);
    stdio_sema.release();
}
void test_thread(void const *args){
    while(1){
        notify((const char*)args, 0);
    }
}
int main(){

    t2.start(callback(test_thread, (void *)"Th 2"));
    t3.start(callback(test_thread, (void *)"Th 3"));

    test_thread((void *)"Th 1");
}