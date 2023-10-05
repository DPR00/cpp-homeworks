cmake_minimum_required(VERSION 3.10)
project(homework_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
# Results directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)
add_subdirectory(src)

add_executable(${PROJECT_NAME} src/homework_4.cpp)

target_link_libraries(${PROJECT_NAME} ipb_algorithm)

enable_testing()
add_subdirectory(tests)
