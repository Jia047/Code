#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

typedef char *String;

/* structure */
struct nlist /* 链表项 */
{
    struct nlist *next; /* 链表中的下一项 */
    String name;        /* 定义的名字 */
    String defn;        /* 替换的名字 */
};

static struct nlist *hashtab[HASHSIZE]; /* 指针表 */

/* hash */
unsigned hash(String s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup */
struct nlist *lookup(String s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;

    return NULL;
}

/* 
    allocate memory for string randomly, and return the first address of the memory 
*/
char *__strdup(char *s)
{
    char *retval;

    retval = (char *)malloc(sizeof(char) * (strlen(s) + 1));

    if (retval != NULL)
        strcpy(retval, s);

    return retval;
}

/* install */
struct nlist *install(String name, String defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) /* add */
    {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = __strdup(name)) == NULL)
            return NULL;
        np->defn = __strdup(defn);
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else /* update */
    {
        free((void *)np->defn);
        if ((np->defn = __strdup(defn)) == NULL)
            return NULL;
    }

    return np;
}

void undef(String name)
{
    struct nlist *np = hashtab[hash(name)];

    for (struct nlist *tmp = np; np != NULL; tmp = np, np = np->next)
        if (strcmp(np->name, name) == 0)
        {
            if (tmp == np)
                hashtab[hash(name)] = np->next;
            else
                tmp->next = np->next;
            /*
            free函数只是将参数指针指向的内存归还给操作系统，
            并不会把参数指针置NULL，为了以后访问到被操作系统重新分配后的错误数据，
            所以在调用free之后，通常需要手动将指针置NULL 
            */
            free((void *)np->name);
            free((void *)np->defn);
            free((void *)np);

            break;
        }
}

int main(int argc, char *argv[])
{
    int op = 0;
    struct nlist *np;
    char name[100];
    char defn[100];
    size_t n_name;
    size_t n_defn;
    while (1)
    {
        printf("op: ");
        op = getchar();
        switch (op)
        {
        case '0':
            scanf("%s", name);
            scanf("%s", defn);
            n_name = strlen(name);
            n_defn = strlen(defn);
            // name[n_name - 1] = '\0';
            // defn[n_defn - 1] = '\0';
            install(name, defn);
            memset(name, 0, 100);
            memset(defn, 0, 100);
            break;
        case '1':
            scanf("%s", name);
            // name[n_name - 1] = '\0';
            undef(name);
            memset(name, 0, 100);
            break;
        case '2':
            scanf("%s", name);
            n_name = strlen(name);
            np = lookup(name);
            memset(name, 0, 100);
            // name[n_name - 1] = '\0';
            if (np != NULL)
                printf("[%s, %s]\n", np->name, np->defn);
            printf("==\n");
            break;
        default:
            break;
        }
    }
}