find_package(PNG REQUIRED) 	

add_library(strategies PngIoStrategy.cpp PpmIoStrategy.cpp)
target_link_libraries(strategies  ${PNG_LIBRARY})

target_include_directories(strategies PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
                            "${PROJECT_SOURCE_DIR}/io_strategies"
                            )