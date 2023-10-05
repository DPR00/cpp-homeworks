cmake_minimum_required(VERSION 3.10)
project(hw2_task2)

set(CMAKE_CXX_STANDARD 17) # -std = c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # important

add_executable(task_2 task_2.cpp)

install(TARGETS task_2 DESTINATION bin)
