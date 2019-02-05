#include "mbed.h"
#include "mbed_events.h"

Serial pc(USBTX, USBRX);

DigitalOut led1(LED1);
InterruptIn sw(USER_BUTTON);
EventQueue queue(32 * EVENTS_EVENT_SIZE);
Thread t;

void rise_handler_user_context(void){
    printf("rise handler_user_context in context %p \r\n", Thread::gettid());
    led1 =! led1;
}

void rise_handler(void){
    printf("rise handler %p \r\n", Thread::gettid());
    led1 =! led1;
    queue.call(rise_handler_user_context);
}

void fall_handler(void){
    printf("fall handler %p \r\n", Thread::gettid());
    led1 =! led1;
}
int main(){
    t.start(callback(&queue, &EventQueue::dispatch_forever));
    printf("Starting in context %p \r\n", Thread::gettid());

    sw.rise(rise_handler);
    sw.fall(queue.event(fall_handler));
}