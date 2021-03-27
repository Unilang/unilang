#!/bin/bash
nproc
cat /proc/cpuinfo | grep processor | wc -l
grep -c processor /proc/cpuinfo
grep -c ^processor /proc/cpuinfo
getconf _NPROCESSORS_ONLN
lscpu | grep 'CPU(s):' | head -1 | awk '{print $2}'
hwinfo --short --cpu | wc -l | xargs -I NUMBER expr NUMBER - 1 | xargs
echo $((`cat /sys/devices/system/cpu/present | sed 's/0-//'` + 1))
echo $((`cat /sys/devices/system/cpu/online | sed 's/0-//'` + 1))
echo $((`cat /sys/devices/system/cpu/possible | sed 's/0-//'` + 1))
cat /proc/interrupts | egrep -i 'cpu' | wc -w
python -c 'import multiprocessing as m; print(m.cpu_count())'
python -c 'import psutil as p; print(p.cpu_count())'

#sudo mount --bind /home/luxe/Desktop/other /tmp/TEST_FILE
#check file
#sudo umount /tmp/TEST_FILE
#check file