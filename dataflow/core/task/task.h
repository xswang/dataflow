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
#include "core/ops/matrix_blob.h"

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
      std::vector<std::string> inputs_x = node->input_x_;
      std::string input_name;
      for (int32_t i = 0; i < inputs_x.size(); ++i) {
        // std::cout << inputs_x[i] << std::endl;
        input_name = inputs_x[i];
        // auto matrix_blob =
        //   dynamic_cast<dataflow::MatrixBlob*>(dataflow::CREATE_MATRIX_BLOB(input_name));
        // matrix_blob_register.insert({input_name, matrix_blob});
      }
      // std::cout << std::endl;
      auto op = dynamic_cast<dataflow::Operator*>(dataflow::CREATE_OP(node));
      if (op == nullptr) std::cout << "op null" << std::endl;
      else std::cout << op->get_op_name() << std::endl;
      op->forward();
      // auto matrix_blob =
      //   dynamic_cast<dataflow::MatrixBlob*>(dataflow::CREATE_MATRIX_BLOB(input_name));
    }
  }

 private: 
  Graph graph_;
};

template<typename Graph>
Task<Graph>::Task(Graph graph) : graph_(graph) {}

}

#endif /* !TASK_H*/
