/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Kernel.h"
#include "cmsis_os2.h"

Serial pc(USBTX, USBRX);

DigitalOut led1(LED1);
DigitalOut led2(LED2);
Thread thread;

void on_thread_terminate(osThreadId_t threadID){
    pc.printf("Thread terminate\r\n");
}

void thread2(){
    while(1){
        pc.printf("thread2 thread\r\n");
        led2 = !led2;
        wait(0.5);
    }
}
int main(){
    thread.start(thread2);
    Kernel::attach_thread_terminate_hook(on_thread_terminate);

    wait(3);
    thread.terminate();
    thread.join();

    while(true){
        pc.printf("main thread\r\n");
        led1 = !led1;
        wait(0.5);
    }    
}