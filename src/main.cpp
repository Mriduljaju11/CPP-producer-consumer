#include <iostream>
#include <thread>
#include <vector>
#include "bounded_buffer.h"

/* Function declarations */
void producer(BoundedBuffer<int>& buffer, int producer_id, int items);
void consumer(BoundedBuffer<int>& buffer, int consumer_id, int items);

int main() {
    const int BUFFER_SIZE = 5;
    const int ITEMS_PER_PRODUCER = 10;
    const int PRODUCER_COUNT = 2;
    const int CONSUMER_COUNT = 2;

    BoundedBuffer<int> buffer(BUFFER_SIZE);

    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;

    for (int i = 0; i < PRODUCER_COUNT; i++) {
        producers.emplace_back(producer, std::ref(buffer), i + 1, ITEMS_PER_PRODUCER);
    }

    for (int i = 0; i < CONSUMER_COUNT; i++) {
        consumers.emplace_back(consumer, std::ref(buffer), i + 1,
                               (ITEMS_PER_PRODUCER * PRODUCER_COUNT) / CONSUMER_COUNT);
    }

    for (auto& p : producers) p.join();
    for (auto& c : consumers) c.join();

    std::cout << "\nAll producers and consumers have finished execution.\n";
    return 0;
}
