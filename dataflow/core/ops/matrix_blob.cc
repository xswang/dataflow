/*
 * matrix_blob.cc
 * Copyright (C) 2019 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "core/ops/matrix_blob.h"


namespace dataflow {
REGISTER_MATRIX_BLOB("mnist/data_Reader", MatrixBlob);
REGISTER_MATRIX_BLOB("fc1/out_Innerproduct", MatrixBlob);
REGISTER_MATRIX_BLOB("fc2/out_Innerproduct", MatrixBlob);
REGISTER_MATRIX_BLOB("sigmoid/out_Sigmoid", MatrixBlob);
REGISTER_MATRIX_BLOB("logloss/out_Logloss", MatrixBlob);
}
