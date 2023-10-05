cmake_minimum_required(VERSION 3.10)
project(homework_6)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(io_tools)
add_subdirectory(src)

add_executable(${PROJECT_NAME} src/homework_6.cpp)

target_link_libraries(${PROJECT_NAME} image io_tools)
target_include_directories(image PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
                            "${PROJECT_SOURCE_DIR}/io_tools"
                            )


enable_testing()
add_subdirectory(tests)

