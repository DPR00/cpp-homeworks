add_library(ipb_arithmetic sum.cpp subtract.cpp)


set(installable_libs ipb_arithmetic)
install(TARGETS ${installable_libs} DESTINATION lib)

target_include_directories(ipb_arithmetic PUBLIC
                           "${PROJECT_SOURCE_DIR}/include"
                           )