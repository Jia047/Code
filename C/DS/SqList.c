#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量 
#define LISTINCREMENT 10   // 线性表存储空间的分配增量 
#define NAME(name)(#name)
#define N 10

typedef int Status;
typedef int ElemType;

typedef struct{
	ElemType *elem;    // 存储空间基址
	int length;		   // 当前长度
	int listsize;      // 当前分配的存储容量
}SqList;

Status InitList_Sq(SqList &L){
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

/**
 * 在顺序表的第i个位置之前插入元素e
 */
Status ListInsert_Sq(SqList &L, int i, ElemType e){
	ElemType *newbase;
	ElemType *p, *q;
	if(i < 1 && i > L.length + 1) return ERROR;
	if(L.length >= L.listsize){
		newbase = (ElemType *)malloc((L.listsize + LISTINCREMENT) * sizeof(ElemType));							 
		if(!newbase) exit(OVERFLOW); 
		L.elem = newbase;            // 新基址
		L.listsize += LISTINCREMENT; // 增加存储容量
	}
	q = &(L.elem[i - 1]); // 取得i-1元素的地址
	for(p = &(L.elem[L.length - 1]); p >= q; --p){ // 将 i-1 至 L.length 的元素后移一位，腾出 i-1
		*(p + 1) = *p;
	}
	*q = e;
	L.length++;
	return OK;
}

/**
 * 在顺序线性表L中删除第i个元素，并用e值返回
 */
Status ListDelete_Sq(SqList &L, int i, ElemType &e){
	ElemType *p, *q;
	if(i < 1 || i > L.length + 1) return ERROR;
	p = &(L.elem[i - 1]);
	e = *p;
	q = L.elem + L.length - 1;
	for(++p; p < q; ++p) *(p-1) = *p;
	L.length--;
	return OK;
}

int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType)){
	int i = 1;
	ElemType *p = L.elem;
	while(i <= L.length && !(*compare)(*p++, e)) ++i;
	if(i <= L.length) return i;
	else return 0;
}

/**
 * 合并 La，Lb的元素到Lc，增序
 */
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc){
	ElemType *pa, *pb, *pc;
	ElemType *pa_last, *pb_last;

	pa = La.elem;
	pb = Lb.elem;

	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));

	if(!pc) exit(OVERFLOW);
	
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;

	while(pa <= pa_last && pb <= pb_last){
		if(*pa < *pb){
			*pc++ = *pa++;
		}else{
			*pc++ = *pb++;
		}
	}
	while(pa <= pa_last){
		*pc++ = *pa++;
	}
	while(pb <= pb_last){
		*pc++ = *pb++;
	}
}

void print_Sq(SqList L){
	printf("{L.elem = { ");
	for(int i = 0; i < L.length; i++){
		printf("%d ", L.elem[i]);
	}
	printf(" }, ");
	printf("L.length = %d, ", L.length);
	printf("L.listsize = %d} \n", L.listsize);
}

int main(int args, char* argv[]){
	int a[N] = {1,3,5,7,9,11,13,15,17,19};
	int b[N] = {2,4,6,8,10,12,14,16,18,20};

	SqList La, Lb, Lc;

	InitList_Sq(La);
	InitList_Sq(Lb);

	for(int i = 0; i < N; i++){
		ListInsert_Sq(La, i + 1, a[i]);
		ListInsert_Sq(Lb, i + 1, b[i]);
	}

	print_Sq(La);
	print_Sq(Lb);

	MergeList_Sq(La, Lb, Lc);

	print_Sq(Lc);

	return 0;
}
