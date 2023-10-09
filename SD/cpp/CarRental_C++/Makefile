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
	@valgrind -v --leak-check=yes --show-leak-kinds=all ./$(TARGET)

run: $(TARGET)
	@./$(TARGET)

clean:
	@rm -f $(TARGET)
