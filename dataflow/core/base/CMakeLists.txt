set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/test/base)
add_library(base STATIC test.cc)

add_library(base_shared SHARED test.cc)
