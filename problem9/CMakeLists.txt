cmake_minimum_required(VERSION 3.1)

project(msu2020cppprogs)

set(PROG_SRC main.cpp CIntN.cpp CIntN0.cpp CIntN1.cpp Creator.cpp)
set(PROG_HDR AutoTest.hpp CIntN.hpp CIntN0.h CIntN1.h Creator.h include.h)

configure_file(input.txt input.txt COPYONLY)

add_executable(${PROJECT_NAME} ${PROG_SRC} ${PROG_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -fopenmp -std=c++17")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined -std=c++17")