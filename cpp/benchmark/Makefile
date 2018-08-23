INC_DIR := ${IP}/cpp/benchmark
GXX := g++
FLAGS := -g -std=c++14 -I${INC_DIR}

TARGET := digitsCntBench
TARGET += u64ToAsciiBench

all:	$(TARGET)

digitsCntBench:	${INC_DIR}/digitsCntBenchmark/main.cpp
	$(GXX) $(FLAGS) $< -o $@

u64ToAsciiBench:	${INC_DIR}/u64ToAscii/main.cpp
	$(GXX) $(FLAGS) $< -o $@

clean:
	rm -rf $(TARGET)
