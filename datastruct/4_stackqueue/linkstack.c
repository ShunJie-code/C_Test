#include "stdio.h"
#include "stdlib.h"
#include "linkstack.h"

Status LsPush(LinkStack *s, ElemType e)
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    if (p == NULL)
    {
        perror("Malloc Failed!");
        return ERROR;
    }
    
    p->data = e;
    p->next = s->top;
    s->top = p;
    s->count++;
    return SUCCESS;
}

Status LsPop(LinkStack *s, ElemType *e)
{
    LinkStackPtr p;
    if (LsEmpty(*s))
    {
        printf("\nLink stack is empty!\n");
        return ERROR;
    }
    *e = s->top->data;
    p = s->top;
    s->top = p->next;
    free(p);
    s->count--;
    return SUCCESS;
}

Status LsEmpty(LinkStack s)
{
    if (s.count <= 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
