#!/usr/bin/env bash

for i in {1..9}
do
    # seq 开始 步长 最后
    # 从开始以步长递增至最后
    # 步长默认为 1
    for j in $(seq $i)
    do
        echo -n "$i * $j = $(($i * $j)) |"
    done
    echo ""
done

echo " 2 * 2 = $[2*2]"

for i in $(seq 9)
do
    echo $(($RANDOM % 100))
done
