﻿cmake_minimum_required(VERSION 3.1)

project(msu2020cppprogs)

set(PROG_SRC main.cpp CStringQueue.cpp)
set(PROG_HDR CStringQueue.hpp AutoTest.hpp)

add_executable(${PROJECT_NAME} ${PROG_SRC} ${PROG_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
