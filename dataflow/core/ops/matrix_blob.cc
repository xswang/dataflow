/*
 * matrix_blob.cc
 * Copyright (C) 2019 XiaoshuWang <2012wxs@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "core/ops/matrix_blob.h"


namespace dataflow {
MATRIX_BLOB_REGISTER_IMPLEMENT_REGISTRY(dataflow_matrixblob_registry, MatrixBlob);
std::string mnist_data_Reader = "mnist/data_Reader";
REGISTER_MATRIX_BLOB(mnist_data_Reader, MatrixBlob);
std::string fc1_out_Innerproduct = "fc1/out_Innerproduct";
REGISTER_MATRIX_BLOB(fc1_out_Innerproduct, MatrixBlob);
std::string fc2_out_Innerproduct = "fc2/out_Innerproduct";
REGISTER_MATRIX_BLOB(fc2_out_Innerproduct, MatrixBlob);
std::string sigmoid_out_Sigmoid = "sigmoid/out_Sigmoid";
REGISTER_MATRIX_BLOB(sigmoid_out_Sigmoid, MatrixBlob);
std::string logloss_out_Logloss = "logloss/out_Logloss";
REGISTER_MATRIX_BLOB(logloss_out_Logloss, MatrixBlob);
}
