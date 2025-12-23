#include "bounded_buffer.h"

template <typename T>
BoundedBuffer<T>::BoundedBuffer(size_t cap) : capacity(cap) {}

template <typename T>
void BoundedBuffer<T>::produce(const T& item) {
    std::unique_lock<std::mutex> lock(mtx);

    not_full.wait(lock, [this]() {
        return buffer.size() < capacity;
    });

    buffer.push(item);
    not_empty.notify_one();
}

template <typename T>
T BoundedBuffer<T>::consume() {
    std::unique_lock<std::mutex> lock(mtx);

    not_empty.wait(lock, [this]() {
        return !buffer.empty();
    });

    T item = buffer.front();
    buffer.pop();
    not_full.notify_one();
    return item;
}

/* Explicit template instantiation */
template class BoundedBuffer<int>;
