cmake_minimum_required(VERSION 3.10)
project(homework_3)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

add_executable(homework_3 src/homework_3.cpp)
target_link_libraries(homework_3 PUBLIC html_writer)

target_include_directories(homework_3 PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/api"
                            "${PROJECT_SOURCE_DIR}/include"
                            )
