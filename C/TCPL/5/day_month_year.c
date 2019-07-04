#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/* 根据传入的年份、月份和日期，求出是今年的第几天 */
int day_of_year(int year, int month, int day)
{
    int leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    int retval = 0;
    for(int i = 1; i < month; i++)
    {
        retval += daytab[leap][i];
    }
    return retval + day;
}

int day_of_year_ptr(int year, int month, int day)
{
    int leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for(int i = 1; i < month; i++)
        day += *(*(daytab + leap) + i);
    return day;
}

/* 将某年中第几天转换为某月某日的形式 */
void month_day(int year, int yearday, int* month, int* day)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for(i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }
    *month = i;
    *day = yearday;
}

void month_day_ptr(int year, int yearday, int* month, int* day)
{
    int leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    int i;
    for(i = 1; yearday < *(*(daytab + leap) + i); i++)
        yearday -= *(*(daytab + leap) + i);
    *month = i;
    *day = yearday;
}

int main(int argc, char const *argv[]) {
    int a;
    int month = 0;
    int day = 0;
    a = day_of_year(2019, 3, 1);
    printf("%d\n", a);
    a = day_of_year_ptr(2019, 3,2);
    printf("%d\n", a);
    month_day(2019, 61, &month, &day);
    printf("%d/%d\n", month, day);
    month_day(2019, 62, &month, &day);
    printf("%d/%d\n", month, day);
    return 0;
}
