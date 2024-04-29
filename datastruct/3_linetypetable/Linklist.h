/**
 * 线性表链式存储结构头文件
*/
#include "common.h"

// 数据域与指针域，单链表
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;

void CreateLinkListHead(LinkList *L, int n);
