#!/usr/bin/env bash

# 备份文件夹
log_name=`date "+%Y%m%d"`

tar -czvf /home/jis/code_${log_name}_bak.tar.gz /home/jis/Code
