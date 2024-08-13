#include "circlequeue.h"

Status CQInit(SqQueue *q)
{
    q->front = 0;
    q->rear = 0;
    return SUCCESS;
}

Status CQEnter(SqQueue *q, CQElemType e)
{
    if ((q->rear + 1) % MAXSIZE == q->front)
        return ERROR;
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
    return SUCCESS;
}

Status CQOut(SqQueue *q, CQElemType *e)
{
    if (q->front == q->rear)
        return ERROR;
    *e = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    return SUCCESS;
}

int CQLength(const SqQueue *q)
{
    return (q->rear - q->front + MAXSIZE) % MAXSIZE;
}