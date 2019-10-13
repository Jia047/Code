#include <stdio.h>
/* 不用指定数组的大小，因为初始化后，编译器会自己计算 */
static char* name[] = {
    "Illegal month", "January",
    "February","March","April",
    "May", "June","July", "August",
    "September","October","November",
    "December"
};

/* 根据输入的月份获取月份的名字 */
char* month_day(int n)
{
    return (n < 1 || n > 12) ? name[0] : name[n];
}

int main(int argc, char const *argv[]) {
    char* monthn = month_day(5);
    printf("%s\n", monthn);
    return 0;
}
