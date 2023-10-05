add_library(ipb_algorithm ipb_algorithm.cpp)

target_include_directories(ipb_algorithm PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
                            )