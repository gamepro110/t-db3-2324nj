CXX=g++
CXXFLAGS=-g -Wall -Werror -Wextra -pedantic -ggdb -O0 -std=c++11 -Iproduct
SOURCES=$(wildcard src/*.cpp)
HEADERS=$(wildcard src/*.h)
TARGET=CarRental

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	@$(CXX) $(CXXFLAGS) -o $@ $(SOURCES)

valgrind: $(TARGET) $(SOURCES) $(HEADERS)
	@valgrind --leak-check=yes --show-leak-kinds=all ./$(TARGET)

liltest: $(SOURCES) $(HEADERS) val-test/stringTest.cpp
	@$(CXX) $(CXXFLAGS) val-test/stringTest.cpp src/Car.cpp -I src/ -o $@

runliltest: $(SOURCES) $(HEADERS) liltest val-test/stringTest.cpp
	@valgrind --leak-check=yes --show-leak-kinds=all ./liltest

run: $(TARGET)
	@./$(TARGET)

clean:
	@rm -f $(TARGET) liltest
