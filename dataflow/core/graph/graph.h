/*
 * graph.h
 * Copyright (C) 2017 wangxiaoshu <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

namespace dataflow {

class Edge;
 
class Node {
 public:
  Node(int32_t id, const std::string& name, const std::string type) 
    : name_(name), type_(type), id_(id), input_num_(0) {}
  ~Node() {}

  std::set<Node*> pre_nodes_;
  std::set<Node*> post_nodes_;
  std::set<Edge*> input_edges_;
  std::set<Edge*> output_edges_;

  int32_t input_num_;
  int32_t output_num_;

 public:
  std::string name_;
  std::string type_;
  int32_t id_;
  std::vector<std::string> input_x_;
  std::vector<std::string> input_w_;
  int32_t w_row_num_;
  int32_t w_col_num_;
  
};

class Edge {
 public:
  Edge(Node* src, Node* dst) {}
  ~Edge() {}

  Node* src_;
  Node* dst_;
};

class Graph {
 public:
  Graph() : id_(0) {}
  ~Graph() {}

  Node* NewNode(const std::string& name, const std::string& type);
  Edge* NewEdge(Node* src, Node* dst);
  inline int32_t NewId() {
    return id_++;
  }

  std::unordered_map<std::string, Node*> name_to_node_;
  std::unordered_map<int32_t, Node*> id_to_node_;
  std::unordered_map<std::string, Edge*> name_to_edge_;
  std::unordered_map<int32_t, Edge*> id_to_edge_;

 private:
  std::set<Node*> nodes_;
  std::set<Edge*> edges_;
  int32_t id_;
};

}

#endif /* !GRAPH_H */
