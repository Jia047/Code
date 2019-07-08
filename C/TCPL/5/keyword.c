#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_LINE 1024

typedef char *String;

struct tnode{
    String word;
    unsigned int count;
    struct tnode *lchild;
    struct tnode *rchild;
};
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

    char tmp[MAX_LINE];
    char* find;

    if ((fp = fopen(file_name, "r")) == NULL)
    {
        printf("%s: %s\n", file_err[errno], file_name);
        return 0;
    }

    while (!feof(fp))
    {
        memset(tmp, 0, MAX_LINE);
        fgets(tmp, MAX_LINE, fp);
        line[nlines] = (String)malloc(strlen(tmp));
        // 没有内存分配了，程序应该退出。
        if (line[nlines] == NULL)
            exit(-1);
        strcpy(line[nlines], tmp);
        find = strchr(line[nlines], '\n');
        nlines++;
    }

    fclose(fp);

    return nlines - 1;
} 

struct tnode*
makenode(String w)
{
    if(w == NULL)
        return NULL;
    struct tnode* ret = (struct tnode*)malloc(sizeof(struct tnode));
    if(ret == NULL)
        exit(-1);
    ret->word = (String)malloc(sizeof(strlen(w)));
    if(ret->word == NULL)
        exit(-1);
    strcpy(ret->word, w);
    ret->count = 1;
    ret->lchild = ret->rchild = NULL;

    return ret;
}

/* 将w放到合适的位置，并返回子树的根 */
struct tnode*
addtree(struct tnode *root, String w)
{
    if(root == NULL)
        return makenode(w);

    int comp = strcmp(root->word, w);
    if(comp == 0)
        root->count += 1;
    else if(comp > 0)
        root->lchild = addtree(root->lchild, w);
    else
        root->rchild = addtree(root->rchild, w);
}

void prttree(struct tnode *root)
{
    if(root == NULL)
        return ;
    prttree(root->lchild);
    printf("[word: %s, count: %d]\n", root->word, root->count);
    prttree(root->rchild);
}

int main(int argc, char * argv[])
{
    String line[200];
    String file_name = *++argv;
    long nlines = 0;
    
    struct tnode *root = NULL;

    if((nlines = _readline(line, file_name)) != 0)
    {
        for(int i = 0; i <= nlines; i++)
            root = addtree(root, line[i]);
        
        prttree(root);
    }

    return 0;
}