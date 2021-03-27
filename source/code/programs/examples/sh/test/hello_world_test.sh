#!/usr/bin/env bash
set -euo pipefail
EXPECTED="Hello, World!"
OUTPUT=$(./code/examples/sh/hello_world.sh)

if [ "$OUTPUT" != "$EXPECTED" ]; then
    echo "$OUTPUT != $EXPECTED"
    exit 1
fi
