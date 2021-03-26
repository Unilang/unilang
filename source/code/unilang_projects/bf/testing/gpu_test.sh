#!/bin/bash

#build test without remote
cd ~/Desktop/test_repo;
bazelisk clean
bazelisk build :gpu_test

#run test with remote
bazelisk test -s \
--execution_log_json_file=~/Desktop/gpu_execution.json \
--experimental_remote_grpc_log=~/Desktop/gpu_remote.bin \
--remote_executor=grpc://localhost:8980 :gpu_test

#convert the remote file
cd ~/Desktop/tools_remote;
bazelisk run //:remote_client -- --grpc_log \
~/Desktop/gpu_remote.bin printlog > ~/Desktop/gpu_remote.json

bazelisk run //:remote_client -- --grpc_log \
~/Desktop/gpu_remote.bin failed_actions > ~/Desktop/failed_actions.json

