#!/usr/bin/env bash

echo "hello world"

# PATH 决定了shell将到哪些目录中寻找命令或程序
echo "$PATH is " $PATH
# HOME 当前用户主目录
echo "$HOME is " $HOME
# HISTSIZE　历史记录数
echo "$HISTSIZE is " $HISTSIZE
# LOGNAME 当前用户的登录名
echo "$LOGNAME is " $LOGNAME
# HOSTNAME 指主机的名称
echo "$HOSTNAME is " $HOSTNAME
# SHELL 当前用户Shell类型
echo "$SHELL is " $SHELL
# LANGUGE 语言相关的环境变量，多语言可以修改此环境变量
echo "$LANGUGE is " $LANGUGE
# MAIL 当前用户的邮件存放目录
echo "$MAIL is " $MAIL
# PS1 基本提示符，对于root用户是#，对于普通用户是$
echo "$PS1 is " $PS1

# 单引号字符串
name='baby'
hello='Hello, '$name''
echo $hello

# 双引号字符串
name="baby"
hello="Hello, "$name""
echo $hello

# 字符串拼接
name='jia'
# 使用双引号
greeting="hello, "$name" !"
greeting_1="hello, ${name} !"
echo $greeting $greeting_1
# 使用单引号,使用单引号,无法通过 ${variable} 来引用变量
greeting='hello, '$name' !'
greeting_1='hello, ${name} !'
echo $greeting $greeting_1

# 获取字符串长度
name="hello world"
# 第一种方式
echo ${#name}
# 第二种方式
expr length "$name";

# 使用 expr 命令时，表达式中的运算符左右必须包含空格，如果不包含空格，
# 将会输出表达式本身:
echo '5+6 is' & expr 5+6
echo '5 + 6 is' & expr 5 + 6
echo '5*6 is' & expr 5*6
echo '5 * 6 is' & expr 5 * 6
echo '5 \* 6 is' & expr 5 \* 6

# 截取字符串
str="I am a student"
# str:l:r 取得 [l, r) 之间的子字符串
echo ${str:0:4}

# shell 数组
array=(1 2 3 4 5);
# 获取长度
length=${#array[@]}
length2=${#array[*]}
# 输出长度 5
echo $length
echo $length2
# 输出数组第三个元素
echo ${array[2]}
# 删除某个元素
unset array[1]
# 遍历数组
for i in ${array[@]}; do echo $i ; done
# 删除数组的所有元素
unset array
echo "清空后"
for i in ${array[@]}; do echo $i ; done

# 加法运算符
a=3;b=4
val='expr $a + $b'
val_2="expr $a + $b"
echo $val
echo $val_2

# 关系运算符
a=3;b=4
if [ $a -eq $b ]
then
    echo "$a == $b"
else
    echo "$a != $b"
fi

# 逻辑运算符
a=$(( 1 && 0 ))
echo '1 && 0 = '$a''


# 产生随机数
echo "产生十个随机数"
for i in {0..9};
do
    echo $RANDOM
done

echo "输出 1..5"
for ((i = 1; i <= 5; i++));
do
    echo $i
done;

echo "使用while输出1..5"
int=1
while (( $int <= 5 ))
do
    echo $int
    let "int++"
done

# echo "按下 <CTRL-D> 退出"
# echo -n "输出你最喜欢的电影: "
# while read FILM
# do
#     echo "是的, $FILM 是一部好电影!"
# done

# 函数
function first() {
    echo "这是我的第一 shell 函数"
}

first

# 函数返回值
# function sum() {
#     echo "输入第一个数字"
#     read a
#     echo "输入第二个数字"
#     read b
#     echo "两个数字分别为 $a 和 $b"
#     return $(( $a + $b ))
# }
#
# sum
# echo "连个数字之和为 $?"

function readParam() {
    echo "第一个参数为 $1 !"
    echo "第二个参数为 $2 !"
    echo "第十个参数为 $10 !"
    echo "第十个参数为 ${10} !"
    echo "第十一个参数为 ${11} !"
    echo "参数总数有 $# 个!"
    echo "作为一个字符串输出所有参数 $* !"
}
readParam 1 2 3 4 5 6 7 8 9 10 11 12
