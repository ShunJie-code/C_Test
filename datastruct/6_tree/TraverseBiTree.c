/**
 * 遍历二叉树
 */
#include "common_6.h"
#include <stdio.h>

// 二叉树 前序遍历递归算法
void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}
