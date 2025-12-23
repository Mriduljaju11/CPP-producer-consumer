# ⚙️ C++ Multithreaded Producer–Consumer System

A high-performance, thread-safe implementation of the classic **Producer–Consumer** concurrency problem using **modern C++ (C++17)**.  
The system uses **blocking synchronization (no busy-waiting)** with `std::mutex` and `std::condition_variable` to safely coordinate multiple producer and consumer threads over a **bounded buffer**.

This project demonstrates a strong practical understanding of **Operating Systems fundamentals**, including synchronization, race-condition prevention, and efficient inter-thread communication.

---

## 🚀 Key Features

- Multi-threaded producer and consumer workers  
- Thread-safe bounded buffer (FIFO queue)  
- Efficient synchronization using:
  - `std::mutex` for mutual exclusion  
  - `std::condition_variable` for blocking and signalling  
- No busy-waiting → optimal CPU utilization  
- Prevents race conditions, deadlocks, and lost wakeups  
- Constant-time enqueue and dequeue operations  
- Configurable:
  - Buffer capacity  
  - Number of producers and consumers  
  - Production and consumption rates  
- Clean, modular, and extensible C++ design  

---

## 🧠 Core Concepts Demonstrated

- Concurrency and multithreading  
- Critical sections and mutual exclusion  
- Condition variable signalling:
  - `wait(lock, predicate)`  
  - `notify_one`  
- Bounded-buffer (Producer–Consumer) problem  
- Thread coordination and blocking  
- Avoiding race conditions, deadlocks, and spurious wakeups  

---

## 🏗️ Design Decisions

- Used `wait(lock, predicate)` to safely handle spurious wakeups  
- Employed blocking synchronization instead of busy-waiting for performance  
- Separated producer, consumer, and buffer logic for clear modularity  
- Bounded buffer enforces back-pressure when producers outpace consumers  

---

## 📁 Project Structure

```plaintext
cpp-producer-consumer/
│── src/
│   ├── main.cpp                 # Program entry point
│   ├── producer.cpp             # Producer thread logic
│   ├── consumer.cpp             # Consumer thread logic
│   ├── bounded_buffer.cpp       # Thread-safe bounded queue
│   └── bounded_buffer.h         # Buffer interface
│── README.md                    # Project documentation
│── Makefile                     # Build instructions
```