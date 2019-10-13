#!/usr/bin/env bash

echo -n "login: "
read name
echo -n "password: "
read password
# 布尔运算符
# -a 代表 与
# -o 代表 或
# ! 代表 非
if [ $name = "jia" -a $password = "666" ];
then
    echo -n "welcome, $name, login "
    date
else
    echo "invalid name and password"
fi
