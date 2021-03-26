#!/bin/bash

#build test without remote
cd ~/Desktop/test_repo;
bazelisk clean
bazelisk build :cpu_test

#run test with remote
bazelisk test -s \
--execution_log_json_file=~/Desktop/cpu_execution.json \
--experimental_remote_grpc_log=~/Desktop/cpu_remote.bin \
--remote_executor=grpc://localhost:8980 :cpu_test

#convert the remote file
cd ~/Desktop/tools_remote;
bazelisk run //:remote_client -- --grpc_log ~/Desktop/cpu_remote.bin printlog > ~/Desktop/cpu_remote.json

#bazelisk clean
#bazelisk build :gpu_test
#bazelisk test -s --execution_log_json_file=~/Desktop/execution.json --experimental_remote_grpc_log=~/#Desktop/remote.bin --remote_executor=grpc://localhost:8980 :gpu_test
