#ifdef __cplusplus
extern "C" {
#endif
	#define _LinkList_H 
	#define TRUE 1
	#define FALSE 0
	#define OK 1
	#define ERROR 0
	#define INFEASIBLE -1
	#define OVERFLOW -2

	typedef int Status;
	typedef int ElemType;

	typedef struct LNode{
		ElemType data;
		struct LNode *next;
	}*LinkList;

	Status GetElem_L(LinkList L, int i, ElemType &e);
	Status ListInsert_L(LinkList &L, int i, ElemType e);
	Status ListDelete_L(LinkList &L, int i, ElemType &e);
	void CreateList_L(LinkList &L, int n);
	void ListDisplay_L(LinkList L);
	void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc);

#ifdef __cplusplus
}
#endif
