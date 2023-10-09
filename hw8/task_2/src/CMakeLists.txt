add_library(image image.cpp)

target_link_libraries(image strategies ${PNG_LIBRARY})

target_include_directories(image PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
                            "${PROJECT_SOURCE_DIR}/io_strategies"
                            )