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

namespace dataflow{
class Logloss : public Operator {
 public:
  Logloss() {}
  ~Logloss() {}
  std::string get_op_name() {return "Logloss";}
};

}

#endif /* !LOGLOSS_H */
