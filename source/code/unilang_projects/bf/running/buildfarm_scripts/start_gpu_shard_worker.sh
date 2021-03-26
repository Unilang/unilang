#!/bin/bash
source buildfarm_scripts/move_to_repo.sh
move_to_buildfarm_repo

sleep 4;
printf "\e]2;GPU WORKER\a"
bazelisk run //src/main/java/build/buildfarm:buildfarm-shard-worker ~/Desktop/unilang/source/code/external_projects/bf/running/configs/shard-gpu-worker.config.example
read;
