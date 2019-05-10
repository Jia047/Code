#!/usr/bin/env bash

while true
do
    echo -n "please enter the file name: "
    read file_name
    if test -e $(pwd)/$file_name
    then
        echo "the file is existing Please enter new one"
    else
        mkdir $file_name
        echo "ok"
        break
    fi
done
