add_library(serialization serialize.cpp convert_dataset.cpp)
add_library(kmeans kmeans.cpp)
add_library(bow_dictionary BowDictionary.cpp)

find_package(OpenCV REQUIRED)
target_include_directories(serialization PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
                            )
                        
target_include_directories(kmeans PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
                            )

target_include_directories(bow_dictionary PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
                            )

target_link_libraries(serialization ${OpenCV_LIBS})
target_link_libraries(kmeans ${OpenCV_LIBS} serialization)
target_link_libraries(bow_dictionary ${OpenCV_LIBS} serialization kmeans)

