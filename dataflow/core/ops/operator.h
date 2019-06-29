/*
 * operator.h
 * Copyright (C) 2017 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef OPERATOR_H
#define OPERATOR_H

// #include "core/base/class_register.h"
#include "core/base/op_register.h"
#include "core/ops/blob_matrix.h"
#include "core/graph/graph.h"

namespace dataflow{
class Operator{
 public:
  Operator() {}
  virtual ~Operator() = default;
  virtual std::string get_op_name() {}
  virtual void initialize(Node* node) {}
  virtual void finalize() {}
  virtual void forward() {}
  virtual void backward() {}
 private:
  Node* _node;
};

CLASS_REGISTER_DEFINE_REGISTRY(dataflow_op_registry, Operator)
#define REGISTER_OP(format_name, op_name)             \
    CLASS_REGISTER_OBJECT_CREATOR(                            \
        dataflow_op_registry,                                \
        Operator,                                                \
        format_name,                                          \
        op_name)

#define CREATE_OP(format_name)                           \
    CLASS_REGISTER_CREATE_OBJECT(                             \
        dataflow_op_registry,                                \
        format_name)
}

#endif /* !OPERATOR_H */
