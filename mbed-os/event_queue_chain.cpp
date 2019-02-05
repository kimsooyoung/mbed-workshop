#include "mbed.h"
#include "mbed_events.h"

Serial pc(USBTX, USBRX);

int main(){
    EventQueue a;
    a.call(printf, "hello from a \r\n");

    EventQueue b;
    b.call(printf, "hello from b \r\n");

    EventQueue c;
    c.call(printf, "hello from c \r\n");

    c.chain(&a);
    b.chain(&a);

    a.dispatch();
}