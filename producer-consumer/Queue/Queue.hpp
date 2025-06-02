
#include <semaphore>
#include <mutex>

#define BUFFER_LEN 5

class Queue
{
private:
    std::counting_semaphore<5> semProducer;
    std::counting_semaphore<5> semConsumer;
    std::mutex mutex;
    int data[BUFFER_LEN];

    size_t posProducer;
    size_t posConsumer;
public:
    Queue(/* args */);  // Constructor

    void put(const int data);
    int take(void);
};
