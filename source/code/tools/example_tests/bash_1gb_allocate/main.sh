#!/bin/bash
total_bytes=$((1024**3*1))
echo $total_bytes
sleep_s=5;
cat <( </dev/zero head -c $total_bytes) <(sleep $sleep_s) | tail
#</dev/zero head -c $total_bytes | tail