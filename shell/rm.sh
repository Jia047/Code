#!/usr/bin/env bash

ls

for list_file in '/bin/ls'
do
    if test -d $list_file
    then
        b=0
    else
        a=$( ls -l $list_file | awk '{ print $5 }')
            if test $a -eq 0
            then
                rm $list_file
            fi
    fi
done
