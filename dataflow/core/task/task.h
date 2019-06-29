/*
 * Task.h
 * Copyright (C) 2017 wangxiaoshu <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef TASK_H
#define TASK_H

#include "core/graph/graph.h"
#include "core/graph/graph_iter.h"

namespace dataflow {

template<typename Graph>
class Task {
 public:
  Task(Graph graph);
  ~Task() {}

  inline void run() {
    for(Node* n : graph_.nodes_) {
      std::cout<<n->name_<<":"<<n->input_num_<<std::endl;
    }

    GraphIter<Graph> graph_iter(graph_);
    for(graph_iter.First(); !graph_iter.End(); graph_iter.Next()){
      Node* n = graph_iter.current_;
      std::cout<<"node name: "<<n->id_<<std::endl; 
    }
  }

 private: 
  Graph graph_;
};

template<typename Graph>
Task<Graph>::Task(Graph graph) : graph_(graph) {}

}

#endif /* !TASK*/
