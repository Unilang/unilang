#!/bin/bash
source buildfarm_scripts/move_to_repo.sh
move_to_buildfarm_repo

sleep 3;
printf "\e]2;SERVER\a"
bazelisk run //src/main/java/build/buildfarm:buildfarm-server ~/Desktop/unilang/source/code/external_projects/bf/running/configs/shard-server.config.example
read;
