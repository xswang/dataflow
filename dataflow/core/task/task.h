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
    for(Node* node : graph_.nodes_) {
      // std::cout<<node->name_<<"        input_num: "<<node->input_num_<<std::endl;
      // std::cout << std::endl;
    }

    GraphIter<Graph> graph_iter(graph_);
    for(graph_iter.First(); !graph_iter.End(); graph_iter.Next()){
      Node* node = graph_iter.current_;
      std::cout<<"node name: " << node->name_ << "\tnode type: " << node_type_ <<std::endl; 
      auto op = dynamic_cast<dataflow::Operator*>(dataflow::CREATE_OP(node->type_));
      std::cout << op->get_op_name() << std::endl;
    }
  }

 private: 
  Graph graph_;
};

template<typename Graph>
Task<Graph>::Task(Graph graph) : graph_(graph) {}

}

#endif /* !TASK*/
