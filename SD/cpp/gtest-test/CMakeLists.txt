cmake_minimum_required(VERSION 3.20)
project(gtest-test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(configureTests "configure unit tests" ON)

add_subdirectory(lib)
add_subdirectory(app)

if(configureTests)
    add_subdirectory(tests)
endif(configureTests)

