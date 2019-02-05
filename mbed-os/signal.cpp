/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

Serial pc(USBTX, USBRX);

DigitalOut led1(LED1);
Thread thread;

void thread2(){
    while(1){
        thread.signal_wait(0x1);
        pc.printf("thread2 thread\r\n");
        led1 = !led1;
    }
}
int main(){
    thread.start(thread2);
    //Thread::attach_terminate_hook(on_thread_terminate);
    //Kernel::attach_thread_terminate_hook(on_thread_terminate)

    // wait(3);
    // thread.terminate();
    // thread.join();

    while(true){
        pc.printf("main thread\r\n");
        wait(1.0);
        thread.signal_set(0x1);
    }    
}