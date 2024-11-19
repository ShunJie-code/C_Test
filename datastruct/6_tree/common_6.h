#ifndef _COMMON_6_H_
#define _COMMON_6_H_

typedef char CharElemType;
typedef int IntElemType;

// 二叉树与节点结构定义
typedef struct BiTNode
{
    CharElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 枚举列表自动定1和0，为0时指向孩子，即原链表Link表示，为1时指向线索
typedef enum
{
    Link,
    Thread
} PointerTag;

// 二叉线索树与节点结构定义
typedef struct BiThreadNode
{
    CharElemType data;
    struct BiThreadNode *lchild, *rchild;
    PointerTag ltag;    // 0 左孩子 1 前驱
    PointerTag rtag;    // 0 右孩子 1 后继
} BiThreadNode, *BiThreadTree;

void CreateBiThreadTree(BiThreadTree *ppNode);

void CreateBiTree(BiTree *T);
void DestroyBiTree(BiTree root);
void PreOrderTraverse(BiTree T, int level);
void InOrderTraverse(BiTree bTree, int level);
void PostOrderTraverse(BiTree bTree, int level);
#endif