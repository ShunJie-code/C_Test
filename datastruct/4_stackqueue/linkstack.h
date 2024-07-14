#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
#include "common4.h"
typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;    // 栈顶指针
    int count;           // 栈元素
}LinkStack;

Status LsPush(LinkStack *s, ElemType e);
Status LsPop(LinkStack *s, ElemType *e);
Status LsEmpty(LinkStack s);

#endif