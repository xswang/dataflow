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
#include "core/ops/operator.h"

namespace dataflow {

template<typename Graph>
class Task {
 public:
  Task(Graph graph);
  ~Task() {}

  inline void run() {
    GraphIter<Graph> graph_iter(graph_);
    for(graph_iter.First(); !graph_iter.End(); graph_iter.Next()){
      Node* node = graph_iter.current_;
      // std::cout<<"node name: " << node->name_ << "\tnode type: " << node->type_ <<std::endl; 
      // auto op = dynamic_cast<dataflow::Operator*>(dataflow::CREATE_OP(node->type_));
      auto op = dynamic_cast<dataflow::Operator*>(dataflow::CREATE_OP(node));
      // std::cout << op->get_op_name() << std::endl;
    }
  }

 private: 
  Graph graph_;
};

template<typename Graph>
Task<Graph>::Task(Graph graph) : graph_(graph) {}

}

#endif /* !TASK_H*/
