#include <stdio.h>
#include <stdlib.h>
#include "binarySortTree.h"

void PreOrderTraverse(BiTree T, int level)
{
    if (T == NULL)
    {
        return;
    }
    printf("%d 位于第 %d 层\n", T->data, level);
    PreOrderTraverse(T->lchild, level + 1);
    PreOrderTraverse(T->rchild, level + 1);
}

bool BST_Search(BiTree T, int key, BiTNode *f, BiTNode **p)
{
    if (!T)
    {
        *p = f;
        return false;
    }
    else if (key == T->data)
    {
        *p = T;
        return true;
    }
    else if (key < T->data)
        return BST_Search(T->lchild, key, T, p); // 小，往左子树递归
    else
        return BST_Search(T->rchild, key, T, p); // 大，往右子树递归
}

bool BST_Inseart(BiTree *T, int key)
{
    BiTree p, s;
    if (!BST_Search(*T, key, NULL, &p))
    {
        s = (BiTNode *)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = NULL;
        s->rchild = NULL;
        // 如果p为空代表树为空
        if (!p)
            *T = s;
        else if (key < p->data)
            p->lchild = s;
        else
            p->rchild = s;
        return true;
    }
    return false;
}
