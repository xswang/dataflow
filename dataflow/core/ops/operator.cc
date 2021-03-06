/*
 * operator.cc
 * Copyright (C) 2017 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "core/ops/operator.h"
#include "core/ops/reader.h"
#include "core/ops/fully_connected.h"
#include "core/ops/conv.h"
#include "core/ops/pooling.h"
#include "core/ops/sigmoid.h"
#include "core/ops/logloss.h"

namespace dataflow {
CLASS_REGISTER_IMPLEMENT_REGISTRY(dataflow_op_registry, Operator);
std::string OP_Reader = "Reader";
REGISTER_OP(OP_Reader, Reader);
std::string OP_FullyConnected = "FullyConnected";
REGISTER_OP(OP_FullyConnected, FullyConnected);
// REGISTER_OP("Conv", Conv);
// REGISTER_OP("Pooling", Pooling);
std::string OP_Sigmoid = "Sigmoid";
REGISTER_OP(OP_Sigmoid, Sigmoid);
std::string OP_Logloss = "Logloss";
REGISTER_OP(OP_Logloss, Logloss);
}
