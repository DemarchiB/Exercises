#include "Queue.hpp"

#include <iostream>


Queue::Queue(/* args */) : semProducer(5), semConsumer(0)
{

}

void Queue::put(const int data)
{
    semProducer.acquire();
    mutex.lock();
    std::cout << "Produced " << data << std::endl;
    this->data[posProducer] = data;

    posProducer++;
    posProducer %= BUFFER_LEN;
    mutex.unlock();
    semConsumer.release();
}

int Queue::take(void)
{
    semConsumer.acquire();
    mutex.lock();
    const int retData = data[posConsumer];

    std::cout << "Consumed " << retData << std::endl;
    posConsumer++;
    posConsumer %= BUFFER_LEN;
    mutex.unlock();
    semProducer.release();

    return retData;
}