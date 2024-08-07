#include <stdio.h>
#include <stdlib.h>
#include "sequencestack.h"
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

void StackInit(SqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (s->base == NULL)
    {
        perror("malloc Failed");
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
        {
            perror("realloc Failed");
            exit(0);
        }
            
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
    s->top = s->base;
}

void StackDestroy(SqStack *s)
{
    // 事实上，realloc的内存也只需要free一次即可
    free(s->base);
    s->base = NULL;
    s->top = NULL;
    s->stackSize = 0;
}

int StackLen(SqStack s)
{
    return s.top - s.base;
}