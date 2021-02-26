#!/bin/bash
total_bytes=$((1024**2*1))
sleep_s=5;
cat <( </dev/zero head -c $total_bytes) <(sleep $sleep_s) | tail
#</dev/zero head -c $total_bytes | tail