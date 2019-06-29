/*
 * operator.cc
 * Copyright (C) 2017 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "core/ops/operator.h"
#include "core/ops/reader.h"
#include "core/ops/innerproduct.h"
#include "core/ops/sigmoid.h"
#include "core/ops/logloss.h"

namespace dataflow{
CLASS_REGISTER_IMPLEMENT_REGISTRY(dataflow_op_registry, Operator);
REGISTER_OP("Reader", Reader);
REGISTER_OP("Innerproduct", Innerproduct);
REGISTER_OP("Sigmoid", Sigmoid);
REGISTER_OP("Logloss", Logloss);
}

