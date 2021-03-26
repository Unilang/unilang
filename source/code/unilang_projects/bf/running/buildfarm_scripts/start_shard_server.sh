#!/bin/bash
source buildfarm_scripts/move_to_repo.sh
move_to_buildfarm_repo

sleep 3;
printf "\e]2;SERVER\a"
bazelisk run //src/main/java/build/buildfarm:buildfarm-server $PWD/examples/shard-server.config.example
read;
