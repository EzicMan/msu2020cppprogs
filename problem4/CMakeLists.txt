cmake_minimum_required(VERSION 3.1)

project(msu2020cppprogs)

set(PROG_SRC main.cpp lzwCompressor.cpp)
set(PROG_HDR lzwCompressor.hpp AutoTest.hpp Trie.hpp)

add_executable(${PROJECT_NAME} ${PROG_SRC} ${PROG_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -std=c++11")
