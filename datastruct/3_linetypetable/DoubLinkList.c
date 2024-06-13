/**
 * p21 双向链表简介，包括循环双向链表
 * p22 算法：实现字母数组的移动
 */
#include <stdio.h>
#include <stdlib.h>
#include "DoubLinkList.h"

Status DLL_Init(DuLinkList *l)
{
    DualNode *head;  
    DualNode *p;                                    // 当前节点
    DualNode *q;                                    // 新申请的节点
    *l = (DuLinkList)malloc(sizeof(DualNode));
    if (*l == NULL)
    {
        return ERROR;
    }
    head = *l;
    head->prior = NULL;
    head->next = NULL;
    p = head;
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
    // 双向链表循环起来，但是头节点不参与，head是一个媒介
    p->next = head->next;
    head->next->prior = p;
    (*l) = head->next;

    free(head);
    return OK;
}

void DLL_ShowList(DuLinkList const l)
{
    DuLinkList dll;
    dll = l;
    if (l == NULL)
    {
        return;
    }
    do
    {
        printf("%c ", dll->data);
        dll = dll->next;
    } while (dll != l);
    printf("\n");

    dll = dll->prior;
    do
    {
        printf("%c ", dll->data);
        dll = dll->prior;
    } while (dll != l->prior);
    
    printf("\n");
}

void Caesar(DuLinkList *l, int i)
{
    if (i > 0)
    {
        do
        {
            (*l) = (*l)->next;
        } while (--i);
    }
    if (i < 0)
    {
        do
        {
            (*l) = (*l)->prior;
        } while (++i);
    }
}