#include "mbed.h"
#include "mbed_events.h"

Serial pc(USBTX, USBRX);
EventQueue queue;
int id;
Timeout cancel;

void event_cancel(){
    pc.printf("event cancel \r\n");
    queue.cancel(id);
}

int main(){
    queue.call(printf, "called immediately\r\n");
    queue.call_in(2000, printf, "called in 2seconds\r\n");
    id = queue.call_every(1000, printf, "called every 1 seconds \r\n");
    pc.printf("event id: %d \r\n", id);

    cancel.attach(event_cancel, 10.0);
    //a.call_every(1000, printf, "called every 1 seconds \r\n");

    queue.dispatch();
    // while(1){
    //     for(int i=0;i<10;i++){
    //         wait(1);
    //     }
    //     queue.cancel(id);
    // }
}