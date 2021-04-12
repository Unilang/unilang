#!/bin/bash
source buildfarm_scripts/move_to_repo.sh
move_to_buildfarm_repo

sleep 4;
printf "\e]2;CPU WORKER\a"
bazelisk run //src/main/java/build/buildfarm:buildfarm-shard-worker ~/Desktop/unilang/source/code/unilang_projects/bf/running/configs/shard-cpu-worker.config.example
read;
