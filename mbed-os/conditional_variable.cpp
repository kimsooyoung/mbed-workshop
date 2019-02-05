#include "mbed.h"

Mutex mutex;
ConditionVariable cond(mutex);

// These variables are protected by locking mutex
// use EventQueue rather than this one
uint32_t count = 0;
bool done = false;

void worker_thread()
{
    mutex.lock();
    do {
        printf("Worker: Count %lu\r\n", count);

        // Wait for a condition to change
        cond.wait();

    } while (!done);
    printf("Worker: Exiting\r\n");
    mutex.unlock();
}

int main() {
    Thread thread;
    thread.start(worker_thread);

    for (int i = 0; i < 5; i++) {

        mutex.lock();
        // Change count and signal this
        count++;
        printf("Main: Set count to %lu\r\n", count);
        cond.notify_all();
        mutex.unlock();

        wait(1.0);
    }

    mutex.lock();
    // Change done and signal this
    done = true;
    printf("Main: Set done\r\n");
    cond.notify_all();
    mutex.unlock();

    thread.join();
}