/**
 * p10 单链表的定义,与查找
 * p11 单链表的插入
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Linklist.h"

void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;
    srand(time(NULL));
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;//优先级原因所以要有括号
    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

Status GetElem(LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p;
    p = L->next;   //用p来记录链表的第一个地址
    j = 1;

    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
    {
        return ERROR;
    }

    *e = p->data;
    return OK;
}

// 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
Status ListInsert(LinkList *L, int i, ElemType e)
{
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
    {
        return ERROR;
    }
    s->data=e;

    // 返回为空指针，强制转换为Linklist类型指针
    s = (LinkList)malloc(sizeof(Node));
    // 先插入指针后插入值
    s->next = p->next;
    p->next = s;
    return 0;
}