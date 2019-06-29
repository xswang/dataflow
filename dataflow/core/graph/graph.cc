/*
 * graph.cc
 * Copyright (C) 2017 wangxiaoshu <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "core/graph/graph.h"

namespace dataflow {

Node* Graph::NewNode(const std::string& name, const std::string& type) {
  int32_t node_id = NewId();
  Node* node = new Node(node_id, name, type);
  return node;
}

Edge* Graph::NewEdge(Node* src, Node* dst) {
  Edge* edge = new Edge(src, dst);
  edge->src_ = nullptr;
  edge->dst_ = nullptr;
  return edge;
}

}


