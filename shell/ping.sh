#!/usr/bin/env bash

for i in {1..255}
do
    echo "the number of $i computer is"
    # 只发送一次 IMCP 包
    ping -c 1 192.168.1.$i >> ping.log
done
