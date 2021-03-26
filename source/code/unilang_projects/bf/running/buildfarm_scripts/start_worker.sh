#!/bin/bash
source buildfarm_scripts/move_to_repo.sh
move_to_buildfarm_repo

sleep 3;
printf "\e]2;CPU WORKER\a"
bazelisk run //src/main/java/build/buildfarm:buildfarm-operationqueue-worker $PWD/examples/worker.config.example
read;
