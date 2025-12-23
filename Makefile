CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread

SRC = src/main.cpp src/producer.cpp src/consumer.cpp src/bounded_buffer.cpp
OUT = producer_consumer

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
