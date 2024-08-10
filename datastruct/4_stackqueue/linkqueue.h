#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
#include "common4.h"

// 将节点重命名为QNode，而节点指针则是QueuePtr
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

Status LQInit(LinkQueue *q);
Status LQEnter(LinkQueue *q, ElemType e);
Status LQOut(LinkQueue *q, ElemType *e);

void LQDestroy(LinkQueue *q);
int LQGetLen(const LinkQueue* q);


#endif