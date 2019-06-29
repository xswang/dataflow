set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/test/graph)

add_library(graph STATIC proto_parse.cc graph.cc udf_graph.cc)
target_link_libraries(graph ${STA_DEPS})
add_library(graph_shared SHARED proto_parse.cc graph.cc udf_graph.cc)
