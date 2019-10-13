#include <stdio.h>
/*
测试 getchar() != EOF 是 0 还是 1
*/
int main(int argc, char const *argv[]) {
    int i = 0;
    char c = 'A';
    int* ip;
    char* cp;

    ip = &i;
    cp = &c;

    printf("sizeof(ip) = %d", sizeof(ip));
    printf("\nsizeof(cp) = %d", sizeof(cp));

    c = (getchar() != EOF);

    printf("%d", c);

    return 0;
}
