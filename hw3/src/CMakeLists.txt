add_library(html_writer html_writer.cpp image_browser.cpp)

target_include_directories(html_writer PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/api"
                            "${PROJECT_SOURCE_DIR}/include"
                            )