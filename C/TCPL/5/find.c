#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXLINE 1024

/*
读取文本，将文本中的每一行读出到内存，
并将该行的首地址，赋值给 line 的元素，
返回读取的行数
*/
int readline(char* text[], char* file_name)
{
    FILE* fp;
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

int main(int argc, char *argv[]) {
    char* line[200];
    char* file_name;
    int nlines = 0;
    int c;

    // 程序可选参数
    int except = 0; // 打印不匹配的行
    int number = 0; // 打印行号
    int found = 0;  // 查找结果，如果程序发生错误，返回 -1

    // 优先级 [] > ++ > * (其实二者的优先级是相同的，这是运算次序由结合方向所决定)
    // (*++argv[0] equals **++argv)
    // ++argv 使得 argv 指针指向了下一个可选参数
    while(--argc > 0 && (*++argv)[0] == '-')
    {
        // argc[0] 是可选参数，其先自增然后再去除参数选项
        while(c = *++argv[0])
        {
            switch(c)
            {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default :
                    printf("find: illegal option %c\n", c);
                    // 程序错误，退出循环
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }
    if(argc != 2)
        printf("find -x -n file_name pattern\n");
    else {
        // 获取文件名,然后argv指向模式
        file_name = argv[0];
        argv++;
        if((nlines = readline(line, file_name)) != 0)
        {
            long lineno = 0;
            while(nlines-- > 0)
            {
                if((strstr(line[lineno], *argv) != NULL) != except)
                {
                    if(number)
                    {
                        printf("%-4ld", lineno + 1);
                    }
                    printf("%s", line[lineno]);
                    found++;
                }
                lineno++;
            }
        }
    }


    return found;
}
