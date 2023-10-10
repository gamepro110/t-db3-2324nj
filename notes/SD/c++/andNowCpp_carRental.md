## 4.1

> makefile was pre-made so i can't do those assignments.
>
> did make 2 custom targets

```make
liltest: $(SOURCES) $(HEADERS) val-test/stringTest.cpp
@$(CXX) $(CXXFLAGS) val-test/stringTest.cpp src/Car.cpp -I src/ -o $@

runliltest: $(SOURCES) $(HEADERS) val-test/stringTest.cpp
@valgrind --leak-check=yes --show-leak-kinds=all ./liltest
```

## 4.2

> first run showed no leaks, did get 140+ errors tracing back to `std::cout`...

link to [raw log output](logOutput.md)
