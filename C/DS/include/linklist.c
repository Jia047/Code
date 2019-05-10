#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

/**
 * 取第i个元素
 */
Status GetElem_L(LinkList L, int i, ElemType &e){
	int j;
	LNode *p;

	p = L->next;
	j = 1;

	while(p && j < i){
		p = p->next;
		j++;
	}

	if(!p || j > i) return ERROR;
	e = p->data;
	return OK;
}

/**
 * 将e插入到i前一位置
 */
Status ListInsert_L(LinkList &L, int i, ElemType e){
	LNode *p, *s;
	int j;

	p = L;
	j = 0;

	while(p && j < i - 1){
		p = p->next;
		j++;
	}

	if(!p || j > i) return ERROR;

	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}

/**
 * 将第i个元素删除, 将被删除的元素用e返回
 *
 * 时间复杂度：O(n)
 * 基本操作：判断 j < i - 1
 *
 */
Status ListDelete_L(LinkList &L, int i, ElemType &e){
	LNode *p;
	int j;

	p = L;
	j = 0;

	while(p && j < i - 1){
		p = p->next;
		j++;
	}

	if(!p || j > i) return ERROR;

	e = p->data;
	p->next = p->next->next;
	free(p->next);
	return OK;
}

void CreateList_L(LinkList &L, int n){
	LNode *p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for(int i = 0; i < n - 1; i++){
		p = (LinkList)malloc(sizeof(LNode));
		if(!p) exit(OVERFLOW);
		scanf("%d ", &p->data);
		p->next = L->next;
		L->next = p;
	}
}

void ListDisplay_L(LinkList L){
	LNode *p;

	p = L->next;
	printf("{ L.data = { ");
	while(p){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("}} \n");
}

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc){
	LNode *pa, *pb, *pc;

	pa = La->next;
	pb = Lb->next;
	pc = Lc = La;

	while(pa && pb){
		if(pa->data >= pb->data){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}else{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	free(Lb);
}

