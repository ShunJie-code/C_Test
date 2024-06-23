#include "common4.h"

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;    // 当前可以使用的最大容量
}SqStack;

void StackInit(SqStack *s);
void StackPush(SqStack *s, ElemType e);
Status StackPop(SqStack *s, ElemType *e);

/**
 * 返回栈的长度
 */
int StackLen(SqStack s);
void StackClear(SqStack *s);
void StackDestroy(SqStack *s);