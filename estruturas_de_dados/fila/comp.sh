#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

FILE_NAME="fila"
NODE_LIB_PATH="$SCRIPT_DIR/../../includes/node.c"
OUTPUT="$SCRIPT_DIR/$FILE_NAME.out"

gcc "$SCRIPT_DIR/$FILE_NAME.c" "$NODE_LIB_PATH" -o "$OUTPUT" && "$OUTPUT"
