#!/bin/bash
printf "\e]2;redis\a"

sudo rm -rf /tmp/worker/*
sudo rm -rf /tmp/worker2/*
sudo rm -rf /tmp/gpu_worker/*
sudo mkdir /tmp/worker; sudo chmod 777 /tmp/worker;
sudo mkdir /tmp/worker2; sudo chmod 777 /tmp/worker2;
sudo mkdir /tmp/gpu_worker; sudo chmod 777 /tmp/gpu_worker;

#make sure redis is downloaded
if [ ! -d ~/Desktop/redis ]; then
	git clone git@github.com:redis/redis.git ~/Desktop/redis
    cd ~/Desktop/redis;
    make all;
fi

#and configured properly
sed -i 's/30000/6378/g' ~/Desktop/redis/utils/create-cluster/create-cluster

#use their create cluster script
cd ~/Desktop/redis/utils/create-cluster/
./create-cluster start
printf 'yes' | ./create-cluster create
redis-cli -c -p 6379 FLUSHALL
redis-cli -c -p 6380 FLUSHALL
redis-cli -c -p 6381 FLUSHALL
redis-cli -c -p 6382 FLUSHALL
redis-cli -c -p 6383 FLUSHALL
redis-cli -c -p 6384 FLUSHALL
read;
