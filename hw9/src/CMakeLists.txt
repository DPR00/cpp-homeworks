add_library(kmeans kmeans.cpp)
add_library(bow_dictionary BowDictionary.cpp)
add_library(histogram histogram.cpp)

find_package(OpenCV REQUIRED)
                        
target_include_directories(kmeans PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
                            )

target_include_directories(bow_dictionary PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
                            )
    
target_include_directories(histogram PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/include"
                            )

target_link_libraries(kmeans ${OpenCV_LIBS})
target_link_libraries(bow_dictionary ${OpenCV_LIBS} kmeans)
target_link_libraries(histogram ${OpenCV_LIBS} bow_dictionary kmeans)
