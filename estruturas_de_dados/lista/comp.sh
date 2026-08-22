#!/bin/bash

FILE_NAME="lista"
NODE_LIB_PATH="../../includes/node.c"

gcc $FILE_NAME".c" $NODE_LIB_PATH -o $FILE_NAME
