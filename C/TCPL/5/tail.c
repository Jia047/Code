#include <stdio.h>

#define LINE_SIZE 1024

/*
读取文本，将文本中的每一行读出到内存，
并将该行的首地址，赋值给 line 的元素，
返回读取的行数
*/
int readline(char* line[], char* file_name)
{
    FILE* fp;
    char str[STR_SIZE];
    int nlines = 0;
    if(!(fp = fopen(file_name, "r")))
    {
        printf("errno: %d", errno);
        system("pause");
        return 0;
    }
    while(!feof(fp))
    {
        fgets(str, STR_SIZE, fp);
        line[nlines] = (char*)malloc(strlen(str));
        if(line[nlines] == NULL)
        {
            exit(-1);
        }
        strcpy(line[nlines], str);
        nlines++;
    }

    return nlines;
}

void writeline(char* line[], int nlines)
{
    while(nlines-- > 0)
        printf("%s", *line++);
}

int main(int argc, char *argv[]) {
    char* line[200];

    int number = 0; // 是否显示行号

    return 0;
}
