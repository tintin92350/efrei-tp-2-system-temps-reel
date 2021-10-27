#!/bin/bash

pid=$1
count=${2:-10}

for i in $(seq $count); do
    echo "[${i}] kill process ${pid}"
    kill -s SIGUSR1 $pid
done