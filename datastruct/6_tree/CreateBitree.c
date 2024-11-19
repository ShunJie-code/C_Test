/*二叉树、线索二叉树存储结构定义*/
#include "common_6.h"
#include <stdio.h>
#include <stdlib.h>

// 创建线索树，默认用户按照前序遍历输入,输入是根节点指针的指针
void CreateBiThreadTree(BiThreadTree *ppNode)
{
    char c;
    scanf("%c", &c);
    if (' ' == c)
    {
        *ppNode = NULL;
    }
    else
    {
        *ppNode = (BiThreadNode *)malloc(sizeof(BiThreadNode));
        (*ppNode)->data = c;
        // 先默认有左右孩子，再线索化
        (*ppNode)->ltag = Link;
        (*ppNode)->rtag = Link;
        CreateBiThreadTree(&(*ppNode)->lchild);
        CreateBiThreadTree(&(*ppNode)->rchild);
    }
}

// 按前序输入二叉树中结点的值，#表示空树
void CreateBiTree(BiTree *T)
{
    CharElemType ch;
    scanf("%c", &ch);
    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        if (!*T)
            return;// exit(OVERFLOW); 内存申请失败
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

void DestroyBiTree(BiTree root)
{
    if (root == NULL)
    {
        return;
    }
    DestroyBiTree(root->lchild);
    DestroyBiTree(root->rchild);
    printf("释放 %c\n", root->data);
    free(root);
    root = NULL;    //  防止野指针
}