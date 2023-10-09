cmake_minimum_required(VERSION 3.10)
project(homework_8)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
add_subdirectory(io_strategies)

add_executable(${PROJECT_NAME} src/homework_8.cpp)

target_link_libraries(${PROJECT_NAME} image strategies ${PNG_LIBRARY})

target_include_directories(${PROJECT_NAME} PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
                            "${PROJECT_SOURCE_DIR}/io_strategies"
                            )


enable_testing()
add_subdirectory(tests)
