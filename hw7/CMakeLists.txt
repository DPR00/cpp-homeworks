cmake_minimum_required(VERSION 3.10)
project(homework_7)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
add_subdirectory(src)

add_executable(${PROJECT_NAME} src/homework_7)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS}
                        serialization bow_dictionary kmeans)

enable_testing()
add_subdirectory(tests)


