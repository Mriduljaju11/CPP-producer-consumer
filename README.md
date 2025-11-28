# ⚙️ C++ Multithreaded Producer–Consumer System

A high-performance implementation of the classic **Producer–Consumer** concurrency problem using **C++ threads, mutex, condition variables, and a thread-safe bounded buffer**. The project demonstrates strong understanding of operating systems concepts, synchronization primitives, race conditions, and concurrent task execution.

---

## 🚀 Features

- Multi-threaded producer and consumer workers  
- Thread-safe **bounded buffer (queue)**  
- Synchronization using:  
  - `std::mutex`  
  - `std::condition_variable`  
- Prevents race conditions and deadlocks  
- Supports configurable production/consumption rates  
- Clean, modular, and extensible C++ design  

---

## 🧠 Core Concepts Demonstrated

- Concurrency and multithreading  
- Critical sections and mutual exclusion  
- Condition variable signalling (`wait`, `notify_one`, `notify_all`)  
- Bounded-buffer (producer–consumer) problem  
- Thread coordination  
- Avoiding deadlocks and spurious wakeups  

---

## 📁 Project Structure

```plaintext
cpp-producer-consumer/
│── src/
│   ├── main.cpp                 # Entry point
│   ├── producer.cpp             # Producer thread implementation
│   ├── consumer.cpp             # Consumer thread implementation
│   ├── bounded_buffer.cpp       # Thread-safe queue
│   └── bounded_buffer.h         # Header for buffer
│── README.md                    # Documentation
│── Makefile                     # Build instructions (optional)
```

---

## ▶️ How It Works

### Producer
- Generates items (integers/tasks)  
- Waits if buffer is full  
- Pushes items into the thread-safe queue  

### Consumer
- Waits if buffer is empty  
- Pops items from the queue  
- Processes each item  

### Synchronization
- `mutex` protects shared data  
- `condition_variable` coordinates waiting & wake-up  
- Prevents busy-waiting, ensures efficient CPU usage  

---

## 🛠️ Build & Run

### 1️⃣ Compile the project
Using g++:

```bash
g++ src/*.cpp -pthread -o producer_consumer
```

### 2️⃣ Run the executable
```bash
./producer_consumer
```

---

## 📥 Example Output

```
Producer 1 produced item: 42
Consumer consumed item: 42
Producer 1 produced item: 57
Consumer consumed item: 57
...
```

Shows proper synchronization between threads.

---

## 🎯 Use Cases

- Operating system simulations  
- Multithreaded task pipelines  
- Real-time processing systems  
- Understanding thread synchronization  

---

## 🤝 Contributions

Suggestions and improvements are welcome!  
Feel free to open issues or submit PRs.

---

## 📜 License

Released under the **MIT License**.
