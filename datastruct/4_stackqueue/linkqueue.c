/**
 * 栈一般用顺序存储结构实现
 * 队列一般用链式存储结构实现
 */
#include "stdio.h"
#include "stdlib.h"
#include "linkqueue.h"

Status LQEmpty(const LinkQueue *q)
{
    if (q->front == q->rear)
        return TRUE;
    return FALSE;
}

Status LQInit(LinkQueue *q)
{
    q->front = (QueuePtr)malloc(sizeof(QNode));
    if (!q->front)
    {
        return ERROR;
    }
    q->front->next = NULL;
    q->rear = q->front;
    return SUCCESS;
}

Status LQEnter(LinkQueue *q, ElemType e)
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
    {
        return ERROR;
    }
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    return SUCCESS;
}

Status LQOut(LinkQueue *q, ElemType *e)
{
    QueuePtr p;
    if (LQEmpty(q) == TRUE)
    {
        printf("\nOut of queue fail, queue is empty!\n");
        return ERROR;
    }
    // 头节点不存数据
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if (q->rear == p)
    {
        q->rear = q->front;
    }
    free(p);
    return SUCCESS;
}

void LQDestroy(LinkQueue *q)
{
    // 包括头结点，全部消除，其他的API都不能用
    while (q->front)
    {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
}

int LQGetLen(const LinkQueue* q)
{
    int len = 0;

    QueuePtr p = q->front->next;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}
