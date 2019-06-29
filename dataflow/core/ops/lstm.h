/*
 * lstm.h
 * Copyright (C) 2018 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef LSTM_H
#define LSTM_H

#include <string>

#include "core/ops/operator.h"

namespace dataflow {
class Lstm : public Operator {
 public:
  Lstm() {}
  ~Lstm() {}
  std::string get_op_name() { return "Lstm"; }

  void initialize(Node* node) {
    std::cout << "initialize " << node->name_ << std::endl;
  }

};
}

#endif /* !LSTM_H */
