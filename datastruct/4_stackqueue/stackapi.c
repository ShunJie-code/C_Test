#include <stdio.h>
#include <stdlib.h>
#include "stackapi.h"
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
    s->top = s->base;
}

void StackDestroy(SqStack *s)
{
    int i, len;
    len = s->stackSize;
    for (i = 0; i < len; i++)
    {
        printf("i = %d, *(s->base) = %d\n", i, *(s->base));
        printf("i = %d, *(s->base+1) = %d\n", i, *(s->base + 1));
        printf("%d: addr = %p\n", __LINE__, s->base);
        // 事实上，realloc的内存也只需要free一次即可
        free(s->base);
        if (1)
        {
            printf("%d: addr = %p\n", __LINE__, s->base);
            printf("%d: addr = %p\n", __LINE__, s->base + 1);
        
            printf("i = %d, *(s->base) = %d, Stack is free!\n", i, *(s->base));
            printf("i = %d, *(s->base+1) = %d, Stack is free!\n", i, *(s->base + 1));
            printf("i = %d, *(s->base+2) = %d, Stack is free!\n", i, *(s->base + 2));
            printf("i = %d, *(s->base+3) = %d, Stack is free!\n", i, *(s->base + 3));
            printf("i = %d, *(s->base+4) = %d, Stack is free!\n", i, *(s->base + 4));
            break;     
        }
        (s->base) += 4;

    }
    s->base = NULL;
    s->top = NULL;
    s->stackSize = 0;
}

int StackLen(SqStack s)
{
    return s.top - s.base;
}