/**
 * 遍历二叉树
 */
#include "common_6.h"
#include <stdio.h>

// 二叉树 前序遍历递归算法
void PreOrderTraverse(BiTree T, int level)
{
    if (T == NULL)
    {
        return;
    }
    printf("%c 位于第 %d 层\n", T->data, level);
    PreOrderTraverse(T->lchild, level + 1);
    PreOrderTraverse(T->rchild, level + 1);
}

void InOrderTraverse(BiTree bTree, int level)
{
    
}