#!/bin/bash 
~/Desktop/redis/utils/create-cluster/create-cluster stop
~/Desktop/redis/utils/create-cluster/create-cluster stop
sudo pkill -9 java
sudo pkill -9 redis-ser
sudo rm -rf /tmp/worker/*
sudo rm -rf /tmp/gpu_worker/*
sudo /etc/init.d/redis-server stop 
#sudo systemctl stop redis.service
sudo rm -rf ~/Desktop/redis/utils/create-cluster/*.log
sudo rm -rf ~/Desktop/redis/utils/create-cluster/*.aof
sudo rm -rf ~/Desktop/redis/utils/create-cluster/*.rdb
sudo rm -rf ~/Desktop/redis/utils/create-cluster/*.conf
