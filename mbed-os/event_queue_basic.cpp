#include "mbed.h"
#include "mbed_events.h"

Serial pc(USBTX, USBRX);

int main(){
    EventQueue a;

    a.call(printf, "called immediately\r\n");
    a.call_in(2000, printf, "called in 2seconds\r\n");
    a.call_every(1000, printf, "called every 1 seconds \r\n");

    a.dispatch();
}