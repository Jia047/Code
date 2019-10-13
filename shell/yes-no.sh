#!/usr/bin/env bash

clear
echo -n "enter [Y/N]: "
read a
case $a in
    y|Y|Yes|YES)echo "you enter $a"
    ;;
    n|N|No|NO)echo "you enter $a"
    ;;
    *)echo "error"
esac
