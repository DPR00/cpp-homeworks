cmake_minimum_required(VERSION 3.10)
project(homework_5)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
add_subdirectory(src)

add_executable(${PROJECT_NAME} src/homework_5.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} mat_serialization convert_dataset)

enable_testing()
add_subdirectory(tests)