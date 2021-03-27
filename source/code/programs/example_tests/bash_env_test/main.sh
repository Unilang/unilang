#!/bin/bash
env
if [ "$MKL_NUM_THREADS" = "1" ]
then
    exit 0;
fi

exit -1;