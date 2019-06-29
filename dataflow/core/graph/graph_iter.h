/*
 * graph.cc
 * Copyright (C) 2017 wangxiaoshu <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef GRAPH_ITER_H
#define GRAPH_ITER_H

#include <queue>
#include <unordered_map>

namespace dataflow {

template<typename Graph>
class GraphIter {
 public:
  GraphIter(Graph graph) : graph_(graph) {}
  ~GraphIter() {}

  void First(); 
  Node* Next();
  bool End();

  void InEdgeCount();
  void UpdateQueue(Node* node);

  Node* current_;
 private:
  Graph graph_;
  std::queue<Node*> queue_;
  std::unordered_map<Node*, int32_t> node_to_inedge_num_;
};

template<typename Graph>
void GraphIter<Graph>::First() {
  node_to_inedge_num_.clear();
  while(!queue_.empty()) queue_.pop();
  InEdgeCount();
  //for(auto n : node_to_inedge_num_){
  //  std::cout<<n.first->name_<<" ::: "<<n.second<<std::endl;
  //}
  if(!queue_.empty()){
    current_ = queue_.front();
    queue_.pop();
    UpdateQueue(current_);
  }
}

template<typename Graph>
Node* GraphIter<Graph>::Next() {
  if(queue_.empty()) current_ = nullptr;
  else {
    current_ = queue_.front();
    queue_.pop();
    UpdateQueue(current_);
  }
} 

template<typename Graph>
bool GraphIter<Graph>::End() {
  return current_ == nullptr;
}

template<typename Graph>
void GraphIter<Graph>::InEdgeCount(){
  for(Node* n : graph_.nodes_) {
    node_to_inedge_num_.insert({n, n->input_num_});
    if(node_to_inedge_num_[n] == 0) queue_.push(n);
  }
}

template<typename Graph>
void GraphIter<Graph>::UpdateQueue(Node* n) {
  for(Edge* e : n->output_edges_) {
    //std::cout<<"start: "<<e->src_->name_<<" -> "<<e->dst_->name_<<std::endl;
    Node* n = e->dst_;
    --node_to_inedge_num_[n];
    if(node_to_inedge_num_[n] == 0) queue_.push(n);
  }
}

}//namespace

#endif /* !GRAPH_ITER_H */
