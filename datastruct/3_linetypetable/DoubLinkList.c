/**
 * p21 双向链表简介，包括循环双向链表
 * p22 算法：实现字母数组的移动
 */
#include <stdio.h>
#include <stdlib.h>
#include "DoubLinkList.h"

Status DLL_Init(DuLinkList *l)
{
    DualNode *p;                                    // 当前节点
    DualNode *q;                                    // 新申请的节点
    *l = (DuLinkList)malloc(sizeof(DualNode));
    if (*l == NULL)
    {
        return ERROR;
    }
    (*l)->prior = NULL;
    (*l)->next = NULL;
    p = (*l);
    for (int i = 0; i < 26; i++)
    {
        q = (DualNode *)malloc(sizeof(DualNode));
        if (q == NULL)
        {
            return ERROR;
        }
        q->data = 'A' + i;
        q->prior = p;
        q->next = p->next;
        p->next = q;
        p = q;
    }
    // 双向链表循环起来，但是头节点不参与
    p->next = (*l)->next;
    (*l)->next->prior = p;
    return OK;
}

void DLL_ShowList(DuLinkList l)
{
    DuLinkList dll;
    dll = l;
    if (l == NULL)
    {
        return;
    }
    dll = dll->next;
    do
    {
        printf("%c ", dll->data);
        dll = dll->next;
    } while (dll != l->next);
    printf("\n");

    dll = dll->prior;
    do
    {
        printf("%c ", dll->data);
        dll = dll->prior;
    } while (dll != l->next->prior);
    
    printf("\n");
}