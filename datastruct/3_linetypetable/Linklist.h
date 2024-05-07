/**
 * 线性表链式存储结构头文件
*/
#include "common.h"

// 数据域与指针域，单链表
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;

void LinkListInitHead(LinkList *L, int n);
void LinkListInitTail(LinkList *L, int n);
void LinklistShow(LinkList L);
Status LinkListClear(LinkList *L);

Status LinkGetElem(LinkList L, int i, ElemType *e);
Status LinkListInsert(LinkList *L, int i, ElemType e);
Status LinkListDelete(LinkList *L, int i, ElemType *e);
