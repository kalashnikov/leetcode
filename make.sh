#!/bin/bash

if [ "$#" -ne 1 ]; then
  echo "Please input source code file."
  exit
fi

#g++ -isystem ${GTEST_DIR}/include -pthread $1 libgtest.a

# Support no main function 
g++ --std=c++11 -isystem ${GTEST_DIR}/include -pthread $1 -lgtest -lgtest_main -L/usr/local/lib
