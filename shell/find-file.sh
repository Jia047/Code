#!/usr/bin/env bash

echo -n "输入一个文件名,将在/home/jis/Code/shell/ 下寻找: "
read file
# 文件运算符
# -e 判断文件是否存在
# -d 判断文件是否是目录
# -f 判断文件是否是普通文件
# -rwx 判断文件是否是　可读可写可执行的
# -s 判断文件是否为空
if test -e /home/jis/Code/shell/$file
then
    echo "文件存在"
else
    echo "文件不存在"
fi
