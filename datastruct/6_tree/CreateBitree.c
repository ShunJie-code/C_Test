/*二叉树的线索二叉树存储结构定义*/
#include "common_6.h"
#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;
typedef enum
{
    Link,
    Thread
} PointerTag; // 枚举列表自动定1和0，为0时指向孩子，为1时指向线索

typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag Ltag;
    PointerTag Rtag;
} BiThrNode, *BiThrTree;

// 创建一颗树，默认用户按照前序遍历输入
// 输入是指针的指针
// void CreateBiTree(BiTree *T)
// {
//     char c;
//     scanf("%c", c);
//     if (' ' == c)
//     {
//         *T = NULL;
//     }
//     else
//     {
//         *T = (BiTNode *)malloc(sizeof(BiTNode));
//         (*T)->data = c;
//         CreateBiTree(&(*T)->lchild);
//         CreateBiTree(&(*T)->rchild);
//     }
// }

// 按前序输入二叉树中结点的值
// #表示空树
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