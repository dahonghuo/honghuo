#!/bin/bash

echo copy the libmemenv.a and libleveldb.a to leveldb/
echo copy autogen-honghuo-man.sh to topdir
cp -rf ./autogen-honghuo-man.sh ../
cp -rf ./libmemenv.a ../src/leveldb
cp -rf ./libleveldb.a ../src/leveldb
