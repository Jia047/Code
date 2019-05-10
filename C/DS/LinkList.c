#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main(int args, char *argv[]){
	LinkList La, Lb, Lc;

	setvbuf(stdout, NULL, _IONBF, 0);
	printf("输入La元素：");
	CreateList_L(La, 5);
	printf("输入Lb元素：");
	CreateList_L(Lb, 5);

	ListDisplay_L(La);
	ListDisplay_L(Lb);

	MergeList_L(La, Lb, Lc);
	
	ListDisplay_L(Lc);

}
