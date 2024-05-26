#include "common.h"
#include <stdint.h>

typedef struct
{
    ElemType data;   // 数据域
    int cur;         // 类似链表中的 next 游标
}Component, StaticLinkList[MAXSIZE];

Status SLL_Init(StaticLinkList space);
Status SLL_Create(StaticLinkList sll, int *arr, uint32_t size);
void SLL_Show(StaticLinkList sll);
Status SLL_Insert(StaticLinkList sll, int i, ElemType e);
Status SLL_Delete(StaticLinkList L, int i);
int SLL_Length(StaticLinkList L);
