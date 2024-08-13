#ifndef _CIRCLEQUEUE_
#define _CIRCLEQUEUE_
#include "common4.h"

typedef int CQElemType;
typedef struct
{
    CQElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

Status CQInit(SqQueue *q);
Status CQEnter(SqQueue *q, CQElemType e);
Status CQOut(SqQueue *q, CQElemType *e);
int CQLength(const SqQueue *q);

#endif