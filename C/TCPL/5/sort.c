#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

#define MAXLINE 1024

typedef char *String;

// 31 bits
static const int MAX_INT = (int)((unsigned)~0 >> 1);
static const int MIN_INT = -1 * (int)((unsigned)~0 >> 1) - 1;

/* 文件读取错误代码 */
String file_err[] = {
    "Invalid.", "Operation not permitted.",
    "No such file or directory", "No such process",
    "Interrupted system call", "Input/output error"};

/* 
    将file_name中的内容读入到line中
    返回行数 nlines，nlies 从 0 开始算起，方便使用下角标或指针运算 
*/
long _readline(String line[], String file_name)
{
    FILE *fp;
    long nlines = 0;
    char tmp[MAXLINE];

    if ((fp = fopen(file_name, "r")) == NULL)
    {
        printf("sort: %s %s\n", file_err[errno], file_name);
        return 0;
    }

    while (!feof(fp))
    {
        memset(tmp, 0, MAXLINE);
        fgets(tmp, MAXLINE, fp);
        line[nlines] = (String)malloc(strlen(tmp));
        // 没有内存分配了，程序应该退出。
        if (line[nlines] == NULL)
            exit(-1);
        strcpy(line[nlines], tmp);
        nlines++;
    }

    fclose(fp);

    return nlines - 1;
}

void _writeline(String line[], long nlines)
{
    while (nlines-- >= 0)
    {
        printf("%s", *line++);
    }
}

/* -r option */
/* just write from the end of array to start*/
void _writeliner(String line[], long nlines)
{
    while (nlines > 0)
        printf("%s", line[nlines--]);
}

/* -f option */
/* the key function, upper to lower*/
int _utl(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return c;
}

int _comp_no_case(String s1, String s2)
{
    int ret;

    if (s1 == NULL && s2 == NULL)
        return 0;
    else if (s1 == NULL)
        return -1;
    else if (s2 == NULL)
        return 1;

    while (*s1 && *s2)
    {
        ret = _utl(*s1) - _utl(*s2);
        if (ret == 0)
        {
            s1++;
            s2++;
        }
        else if (ret > 0)
            return 1;
        else
            return -1;
    }

    return !*s1 ? !*s2 ? 0 : -1 : 1;
}

/* -n option */
/* 
    将字符串转化为整数， 对于空格会跳过，直到碰到第一个+或-号
    对于不合法的字符串或者空字符串将返回 0
    对于溢出处理，如果
    超过最大整数的表示范围，返回MAX_INT：2147483647；
    小于负整数能表示的范围时返回MIN_INT：-2147483648。
 */
int _strtoi(String s)
{

    /* 空字符处理 */
    if (s == NULL)
        return 0;
    while (isspace(*s))
        s++;

    int ret = 0;
    // + or -
    int sign = 1;

    if (*s == '-')
    {
        sign = -1;
        s++;
    }
    else if (*s == '+')
        s++;

    while (isdigit(*s))
    {
        // 溢出处理
        if (sign > 0 && ret > MAX_INT / 10 || (ret == MAX_INT && *s - '0' > MAX_INT % 10))
        {
            ret = MAX_INT;
            break;
        }
        if (sign < 0 && ret > (unsigned)MIN_INT / 10 || (ret == (unsigned)MIN_INT / 10 && *s - '0' > (unsigned)MIN_INT % 10))
        {
            ret = MIN_INT;
            break;
        }
        ret = ret * 10 + *s++ - '0';
    }

    return sign == -1 ? -1 * ret : ret;
}
/* -n option */
int _compi(String s1, String s2)
{
    return _strtoi(s1) - _strtoi(s2);
}

void _swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void _qsort(void *v[], int left, int right, int (*compareto)(void *, void *))
{
    if (left >= right)
        return;
    int i, last;

    _swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
        if (compareto(v[i], v[left]) < 0)
            _swap(v, ++last, i);
    _swap(v, last, left);
    _qsort(v, left, last - 1, compareto);
    _qsort(v, last + 1, right, compareto);
}

int main(int argc, char *argv[])
{
    String line[200];
    long nlines = 0;
    int c;

    /* options */
    int numberic = 0; /* 数值比较 */
    int ign_cas = 0;  /* 忽略大小写 */
    int reverse = 0;  /* 倒转输出 */

    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while (c = *++argv[0])
        {
            switch (c)
            {
            case 'n':
                numberic = 1;
                break;
            case 'f':
                ign_cas = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            default:
                printf("illegal option %c.\n", c);
                // 发生错误，退出程序
                argc = 0;
                break;
            }
        }
    }

    if (argc != 1)
        printf("usage: sort -option file\n");
    else
    {
        // 读取文件
        if ((nlines = _readline(line, *argv)) != 0)
        {
            // gsh
            if (numberic && !ign_cas)
                _qsort(line, 0, nlines, _compi);
            else if (!numberic && ign_cas)
                _qsort(line, 0, nlines, _comp_no_case);
            else if (numberic && ign_cas)
                _qsort(line, 0, nlines, _comp_no_case);

            if (reverse)
                _writeliner(line, nlines);
            else
                _writeline(line, nlines);
        }
    }

    return 0;
}