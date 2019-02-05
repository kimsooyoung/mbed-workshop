/* mbed Microcontroller Library
 * Copyright (c) 2018 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#if 1

#include "mbed.h"

InterruptIn button(D3);
DigitalOut led(D2);

void flip(){
    led = !led;
    wait(0.25);
}
int main(){
    button.mode(PullUp);
    button.fall(&flip);
    while(1){
        wait(1.0);
    }
}
#else

#include "mbed.h"

class Counter{
public:
    Counter(PinName pin) : _interrupt(pin){
        _interrupt.mode(PullUp);
        _interrupt.fall(this, &Counter::increment);
    }
    void increment(){
        _count++;
    }
    int read(){
        return _count;
    }
private:
    InterruptIn _interrupt;
    volatile int _count;
};
Counter counter(D3);
Serial pc(USBTX, USBRX);

int main(){
    pc.baud(115200);
    while(1){
        pc.printf("Count so far : %d \r\n", counter.read());
        wait(1);
    }
}

#endif