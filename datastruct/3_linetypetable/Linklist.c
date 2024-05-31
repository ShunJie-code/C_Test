/**
 * p10 单链表的定义,与查找
 * p11 单链表的插入,与删除
 * p12 单链表的整表创建
 * p13 单链表的整表删除，链表和数组优缺点对比
 * p16 快速找到未知长度单链表的中间节点
 * p17 循环链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Linklist.h"
/**
 * 头插法
*/
void LinkListInitHead(LinkList *L, int n)
{
    LinkList p;
    int i;
#if 0
    srand(time(NULL));
#endif
    // *L = (LinkList)malloc(sizeof(Node));
    if ((*L) == NULL)
    {
        printf("%s-%d\n", __func__, __LINE__);
        *L = (LinkList)malloc(sizeof(Node));
    }
    (*L)->next = NULL;                           // 优先级原因所以要有括号
    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        // p->data = rand() % 100 + 1;
        p->data = i;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}
/**
 * 尾插法
*/
void LinkListInitTail(LinkList *L, int n)
{
    LinkList p;
    LinkList r;
    int i;
    // srand(time(0));
    if ((*L) == NULL)
    {
        printf("%s-%d\n", __func__, __LINE__);
        *L = (Node *)malloc(sizeof(Node));
    }
    
    r = *L;                               // r为迭代节点，指向末尾
    for(i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        // p->data=rand()&100+1;
        p->data = i;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

void LinkListShow(LinkList L)
{
    printf("Link list data: ");
    while (L->next)
    {
        L = L->next;
        printf("%d ", L->data);
    }
    putchar('\n');
}

Status LinkGetElem(LinkList L, int i, ElemType *e)
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
Status LinkListInsert(LinkList *L, int i, ElemType e)
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

    // 返回为空指针，强制转换为Linklist类型指针
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    
    // 先插入指针后插入值
    s->next = p->next;
    p->next = s;
    return 0;
}

Status LinkListDelete(LinkList *L, int i, ElemType *e)
{
    int j;
    LinkList p, q;
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
    // q为 待删除节点
    q = p->next;
    p->next = q->next;

    *e = q->data;
    free(q);
    return OK;
}

Status LinkListClear(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

// 长短步方法，快速找到中间的节点
Status LinkGetMidNode(LinkList L, ElemType *e)
{
    LinkList search, mid;
    mid = L;
    search = L;
    while (search->next != NULL)
    {
        if (search->next->next != NULL)  //若能够移动两步，则动两步，否则一步
        {
            search = search->next->next;
        }
        else
        {
            search = search->next;
        }
        mid = mid->next;
    }
    *e = mid->data;
    return OK;
}