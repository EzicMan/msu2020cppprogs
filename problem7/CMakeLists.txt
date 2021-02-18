cmake_minimum_required(VERSION 3.1)

project(msu2020cppprogs)

set(PROG_SRC main.cpp CIntN.cpp)
set(PROG_HDR AutoTest.hpp CIntN.hpp)

configure_file(input.txt input.txt COPYONLY)

add_executable(${PROJECT_NAME} ${PROG_SRC} ${PROG_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -std=c++11")
