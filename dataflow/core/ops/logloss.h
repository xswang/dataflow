/*
 * logloss.h
 * Copyright (C) 2019 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef LOGLOSS_H
#define LOGLOSS_H
#include <string>

#include "core/ops/operator.h"
#include "core/ops/matrix_blob.h"

namespace dataflow{
class Logloss : public Operator {
 public:
  Logloss() {}
  ~Logloss() {}
  std::string get_op_name() {return "Logloss";}
  void initialize(Node* node) {
    std::cout << node->name_ << std::endl;
    for (int i = 0; i < node->input_x_.size(); ++i) {
      input_name_ = node->input_x_[i];
      std::cout << "input: " << input_name_ << std::endl;
    }
    for (int i = 0; i < node->output_.size(); ++i) {
      output_name_ = node->output_[i];
      std::cout << "output: " << output_name_ << std::endl;
    }
    std::cout << "==================================" << std::endl;
  }

 private:
  Node* _node;
  std::string input_name_;
  std::string output_name_;
};

}

#endif /* !LOGLOSS_H */
