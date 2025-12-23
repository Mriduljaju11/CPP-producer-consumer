#include <iostream>
#include <thread>
#include <chrono>
#include "bounded_buffer.h"

void consumer(BoundedBuffer<int>& buffer, int consumer_id, int items) {
    for (int i = 0; i < items; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        int item = buffer.consume();
        std::cout << "[Consumer " << consumer_id << "] Consumed: " << item << std::endl;
    }
}
