#ifndef _COMMON_6_H_
#define _COMMON_6_H_

typedef int ElemType;
typedef char CharElemType;

// 二叉树的二叉链表节点结构定义
typedef struct BiTNode
{
    CharElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree *T);
void DestroyBiTree(BiTree root);
void PreOrderTraverse(BiTree T, int level);
void InOrderTraverse(BiTree bTree, int level);
void PostOrderTraverse(BiTree bTree, int level);
#endif