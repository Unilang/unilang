#!/bin/bash
mkdir -p /tmp/gpu_worker;
chmod 777 /tmp/gpu_worker;
mkdir -p /tmp/worker;
chmod 777 /tmp/worker;
buildfarm_scripts/fix_redis.sh
gnome-terminal --window -e 'buildfarm_scripts/start_redis.sh' \
--tab -e 'buildfarm_scripts/start_gpu_shard_server.sh' \
--tab -e 'buildfarm_scripts/start_shard_worker.sh' \
--tab -e 'buildfarm_scripts/start_shard_worker2.sh' \
--tab -e 'buildfarm_scripts/go_to_cache.sh'
