cmake_minimum_required(VERSION 3.10)
project(hW2_task1)

set(CMAKE_CXX_STANDARD 17) # -std = c++17
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # important

add_executable(task_1 task_1.cpp)

install(TARGETS task_1 DESTINATION bin)
