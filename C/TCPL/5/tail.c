#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXLINE 1024
#define DEFALUT_CUT 10
/*
读取文本，将文本中的每一行读出到内存，
并将该行的首地址，赋值给 line 的元素，
返回读取的行数
*/
int readline(char* text[], char* file_name)
{FILE* fp;
	if (!(fp = fopen(file_name, "r")))
	{
		printf("file open error.errno: %d\n", errno);
		system("pause");
		return 0;
	}
	int nlines = 0; 
	char line[MAXLINE];
	while (!feof(fp))
	{
		memset(line, 0, MAXLINE);
		fgets(line, MAXLINE, fp);
		text[nlines] = (char*)malloc(strlen(line));
		if (!text[nlines])
		{
			break;
		}
		strcpy(text[nlines], line);
		nlines++;
	}

	fclose(fp);

	return nlines;
}

void writeline(char* line[], int nlines)
{
    while(nlines-- > 0)
        printf("%s", *line++);
}

/* 将字符串转换为整数 */
int ctoi(char* str)
{
    if(str == NULL)
        return -1;

    int ret = 0;
    while(*str)
    {   
        if(*str <= '9' && *str >= '0')
            ret = ret * 10 + *str++ - 48;
        else
            return -1;
    }
    return ret;
}

int main(int argc, char *argv[]) {
    char* line[200];
    // 打印最后 last 行， -1 代表无效
    int last = -1;
    // print from start to the end, invalid when it is -1
    int start = -1;
    int c;

    for (argv++; --argc > 0 && (*argv)[0] == '-' || (*argv)[0] == '+'; argv++)
	{
		if ((*argv)[0] == '-')
		{
			last = ctoi(*argv + 1);
			if (last == -1)
			{
				while (c = *++argv[0])
				{
                    // 在这里可以增加可选参数的判断
					switch (c)
					{
					case 'f':
						/* code */
						break;

					default:
						printf("tail: illegal option %c\n", c);
						argc = 0;
						break;
					}
				}
			}
		}
		else if ((*argv)[0] == '+')
		{
			start = ctoi(*argv + 1);
			if (start == -1)
			{
				printf("tail: illegal option %s\n", *argv);
				argc = 0;
			}
		}
	}

	if (argc != 1)
	{
		printf("usage: tail -n file_name\n");
	}
	else
	{
		char* file_name = *argv;
		int nlines = 0;
		/*
		  文件读取成功才存在打印尾部
		*/
		if ((nlines = readline(line, file_name)) != 0)
		{
			int lineno = 0;
			if (start != -1)
			{
				while (lineno < start - 1)
					lineno++;
			}
			else
			{
				/*
				  如果用户没输入行数，就默认输出 最后 10 行
				  否则根据用户输入的行数来输出
				*/
				int cut = last == -1 ? DEFALUT_CUT : last;
				while (lineno < nlines - cut - 1)
					lineno++;
			}
			while (lineno < nlines)
			{
				printf("%s", line[lineno++]);
			}

		}
	}

	return 0;
}
