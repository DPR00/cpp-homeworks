cmake_minimum_required(VERSION 3.10)
project(homework_8)

set(CMAKE_CXX_STANDARD 17)

add_executable(stack_limit stack_limit.cpp)

install(TARGETS stack_limit DESTINATION bin)

