
#include "Queue.hpp"
#include <thread>

Queue queue;

void producer_handler(void)
{
    int nData = 50;

    while (nData) {
        queue.put(50 - nData);
        nData--;
        std::this_thread::yield();
    }
}

void consumer_handler(void)
{
    int nData = 50;

    while (nData) {
        int data = queue.take();
        nData--;
        std::this_thread::yield();
    }
}


int main(void)
{
    std::thread producer(producer_handler);
    std::thread consumer(consumer_handler);

    producer.join();
    consumer.join();

    return 0;
}