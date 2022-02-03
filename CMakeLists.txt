cmake_minimum_required(VERSION 3.16)
project(EX)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)
file(GLOB SOURCES inc/*.hpp src/*.cpp)

add_executable(test app/test.cpp ${SOURCES})