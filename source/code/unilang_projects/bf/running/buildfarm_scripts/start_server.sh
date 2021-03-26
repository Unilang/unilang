#!/bin/bash
source buildfarm_scripts/move_to_repo.sh
move_to_buildfarm_repo

printf "\e]2;server\a"
bazelisk run //src/main/java/build/buildfarm:buildfarm-server $PWD/examples/server.config.example
read;
