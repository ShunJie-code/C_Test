#include <stdio.h>
#include <stdlib.h>
#include "stackdefine.h"
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 10

void StackInit(SqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (s->base == NULL)
    {
        exit(0);
    }
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

// 注意这种压栈的方法，栈顶没有值
void StackPush(SqStack *s, ElemType e)
{
    // 如果栈满，追加空间
    if (s->top - s->base >= s->stackSize)
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if (!s->base)
            exit(0);
        printf("Realloc stack!\n");
        s->top = s->base + s->stackSize;              // 设置栈顶
        s->stackSize = s->stackSize + STACKINCREMENT; // 设置栈的最大容量
    }
    *(s->top) = e;
    s->top++;
}

Status StackPop(SqStack *s, ElemType *e)
{
    if (s->top == s->base)  
    {
        printf("\n---Stack is empty!---\n");
        return ERROR;
    }
    s->top--;
    *e = *s->top;
    return SUCCESS;
}

void StackClear(SqStack *s)
{

}

void StackDestroy(SqStack *s)
{

}

void StackLen(SqStack s)
{
    
}