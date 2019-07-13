#! /bin/sh
#
# make_start.sh
# Copyright (C) 2019 XiaoshuWang <2012wxs@gmail.com>
#
# Distributed under terms of the MIT license.
#

cp scripts/ProtoBuf.cmake ps-lite/cmake/ 
cp scripts/ProtoBuf.cmake ps-lite-byteps/cmake/ 
mkdir build
cd build
cmake ..
make

