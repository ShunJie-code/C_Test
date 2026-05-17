#include <stdio.h>
#include <stdlib.h>
#include "binarySortTree.h"

// 改变tree结构，需要传tree的指针
bool Delete(BiTree *tree)
{
    BiTree q;
    BiTree s;
    // 1 右子树空，则重接它的左子树
    if ((*tree)->rchild == NULL)
    {
        q = *tree;
        *tree = (*tree)->lchild;
        free(q);
    }
    // 2 左子树空，则重接它的右子树
    else if ((*tree)->lchild == NULL)
    {
        q = *tree;
        *tree = (*tree)->rchild;
        free(q);
    }
    // 3 两边都有，把左子树最大的节点找到
    else
    {
        q = *tree;
        s = (*tree)->lchild;
        while (s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        (*tree)->data = s->data;
        if (q != *tree)
        {
            q->rchild = s->lchild;
        }
        else
        {
            q->lchild = s->lchild;
        }
        free(s);
    }
    return true;
}

void LevelOrderTraverse(BiTree root)
{
    if (root == NULL)
        return;

    // 用数组模拟队列
    BiTNode *queue[1000];
    int front = 0, rear = 0;

    // 根节点入队
    queue[rear++] = root;

    while (front < rear)
    {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++)
        {
            // 出队
            BiTNode *cur = queue[front++];
            printf("%d ", cur->data);

            // 左孩子入队
            if (cur->lchild != NULL)
                queue[rear++] = cur->lchild;
            // 右孩子入队
            if (cur->rchild != NULL)
                queue[rear++] = cur->rchild;
        }
        printf("\n");
    }
}

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

bool BST_Delete(BiTree *tree, int key)
{
    // 不存在关键字为key的数据元素
    if (!*tree)
        return false;
    else
    {
        if (key == (*tree)->data)
            return Delete(tree);
        else if (key < (*tree)->data)
            return BST_Delete(&(*tree)->lchild, key); // 递归查找
        else
            return BST_Delete(&(*tree)->rchild, key); // 递归查找
    }
    return true;
}

bool BST_Create(BiTree *T, int arr[], int len)
{
    bool bRet = true;
    for (int i = 0; i < len; i++)
    {
        bRet = BST_Inseart(T, arr[i]);
        if (bRet == false)
            break;
    }
    return bRet;
}
