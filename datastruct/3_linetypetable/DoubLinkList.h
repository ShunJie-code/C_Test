#include "common.h"

typedef struct DualNode
{
    char data;
    struct DualNode *prior;
    struct DualNode *next;
}DualNode, *DuLinkList;

Status DLL_Init(DuLinkList *l);

void DLL_ShowList(DuLinkList const l);

void Caesar(DuLinkList *l, int i);
