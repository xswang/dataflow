/*
 * udf_graph.cpp
 * Copyright (C) 2017 wangxiaoshu <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "core/graph/udf_graph.h"

#include "core/graph/graph_iter.h"

namespace dataflow {

UdfGraph::UdfGraph(dataflow::GraphDef& graph_def) 
  : graph_def_(graph_def) {
  GraphBuilder();
}
UdfGraph::~UdfGraph() {}

void UdfGraph::GraphBuilder() {
  for(const NodeDef ndef : graph_def_.node_def()){
      // std::cout<<"name = "<<ndef.name()<<"\ttype = "<<ndef.type()<<std::endl;
      BuildNode(ndef);
      // std::cout<<std::endl;
  }
  NodeDef def;
  def.set_name("SOURCE");
}

void UdfGraph::BuildNode(const NodeDef node_def) {
  Node* node = AddNode(node_def.name());
  for(const std::string in : node_def.in()) {
    //std::cout<<"in = "<<in<<std::endl;
    std::size_t pos = in.find("/");
    //std::cout<<"pos = "<<pos<<std::endl;
    std::string input_name = in.substr(0, pos);
    // std::cout<<"input_name = "<<input_name<<std::endl;
    Node* InNode = nullptr;
    std::unordered_map<std::string, Node*>::iterator iter;
    iter = name_to_node_.find(input_name);
    if(iter != name_to_node_.end()){
      InNode = iter->second;
    } else {
      InNode = NewNode(input_name);
    }
    node->pre_nodes_.insert({InNode});
    InNode->post_nodes_.insert({node});
    ++node->input_num_;
    Edge* edge = AddEdge(InNode, node);
  }
}

Node* UdfGraph::AddNode(const std::string& name) {
  Node* n = nullptr;
  n =  NewNode(name);
  nodes_.insert({n});
  name_to_node_.insert({name, n});
  return n;
}

Edge* UdfGraph::AddEdge(Node* src, Node* dst) {
  Edge* e = nullptr;
  e = NewEdge(src, dst);
  e->src_ = src;
  e->dst_ = dst;
  src->output_edges_.insert({e});
  dst->input_edges_.insert({e});
  edges_.insert({e});
  return e;
}

}//namespace dataflow


