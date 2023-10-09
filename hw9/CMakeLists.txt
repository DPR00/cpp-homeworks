cmake_minimum_required(VERSION 3.10)
project(homework_9)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
add_subdirectory(src)

add_executable(${PROJECT_NAME} src/homework_9)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS}
                        bow_dictionary kmeans)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/include"
    )

enable_testing()
add_subdirectory(tests)


