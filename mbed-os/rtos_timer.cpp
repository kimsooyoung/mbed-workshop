#include "mbed.h"

Serial pc(USBTX, USBRX);

void time_func(void){
    pc.printf("timer\r\n");
}
RtosTimer timer(callback(time_func), osTimerPeriodic);

int main(void){
    timer.start(1000);
    wait(5);
    timer.stop();
    timer.start(100);
    wait(1);
    timer.stop();
    while(1){
        wait(2);
    }
}
