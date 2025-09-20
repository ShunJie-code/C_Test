#include <stdbool.h>
#include <stdio.h>
#include "binarySortTree.h"

bool BST_Search(BiTree T, int key, BiTree f, BiTree *p)
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
        return SearchBSF(T->lchild, key, T, p); // 这里输入的变量P就是函数的指针变量
    else
        return SearchBSF(T->rchild, key, T, p); //
}

// 插入操作-当二叉排序树中不存在关键字为key的数据元素时，插入key返回true，否则返回false
bool BST_Inseart(BiTree *T, int key)
{
    BiTree p, s;
    if (!SearchBSF(*T, key, NULL, &p))
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
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
