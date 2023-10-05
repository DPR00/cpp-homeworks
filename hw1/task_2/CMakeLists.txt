cmake_minimum_required(VERSION 3.10)
project(homework_2)

set(CMAKE_CXX_STANDARD 17) # -std = c++17
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # important

add_subdirectory(src)

add_executable(main src/main.cpp)
target_link_libraries(main PUBLIC ipb_arithmetic)

target_include_directories(main PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/include"
                           )

install(DIRECTORY include/ DESTINATION include)
install(TARGETS main DESTINATION bin)
