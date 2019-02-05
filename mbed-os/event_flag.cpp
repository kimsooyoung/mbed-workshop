#include "mbed.h"

EventFlags event;
Thread t3;

void worker_f()
{
    while (true) {
        event.wait_all(0x1);

        printf("Got signal!\r\n");
    }
}

void t3_func(){
    while(1){
        event.wait_all(0x2);
        printf("Got Signal \r\n");
    }
}

int main()
{
    Thread worker;

    worker.start(callback(worker_f));
    t3.start(callback(t3_func)); 

    while (true) {
        wait(1);
        event.set(0x1);
        event.set(0x2);
    }
}