#include <iostream>
#include <thread>
#include <chrono>
#include "bounded_buffer.h"

void producer(BoundedBuffer<int>& buffer, int producer_id, int items) {
    for (int i = 1; i <= items; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        int item = producer_id * 100 + i;
        buffer.produce(item);
        std::cout << "[Producer " << producer_id << "] Produced: " << item << std::endl;
    }
}
