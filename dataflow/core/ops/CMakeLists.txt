set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/test/ops)

set(STA_DEPS base)
add_library(ops STATIC operator.cc)
target_link_libraries(ops ${STA_DEPS})
add_library(ops_shared SHARED operator.cc)
