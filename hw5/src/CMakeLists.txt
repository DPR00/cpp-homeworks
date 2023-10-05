add_library(mat_serialization serialize.cpp)
add_library(convert_dataset convert_dataset.cpp)

find_package(OpenCV REQUIRED)
target_include_directories(mat_serialization PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
                            )
target_include_directories(convert_dataset PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
                            )

target_link_libraries(mat_serialization ${OpenCV_LIBS} convert_dataset)
target_link_libraries(convert_dataset ${OpenCV_LIBS} mat_serialization)

