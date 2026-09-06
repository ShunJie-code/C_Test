#include <stdio.h>
#include "avl_tree.h"
/**
 * @brief 右旋操作
 *
 * @param p
 */
void R_Rotate(AvlTree *p)
{
    AvlTree lTree;
    lTree = (*p)->lchild;         // 1 拿到左子树
    (*p)->lchild = lTree->rchild; // 2 将左子树的右节点，移动到根节点的左侧
    lTree->rchild = (*p);         // 3 根节点作为左子树的右节点
    *p = lTree;                   // 4 更新树的根节点
}

void L_Rotate(AvlTree *p)
{
    AvlTree rTree;
    rTree = (*p)->rchild;         // 1 拿到右子树
    (*p)->rchild = rTree->lchild; // 2 将右子树的左节点，移动到根节点的右侧
    rTree->lchild = (*p);         //
    *p = rTree;
}

/**
 * @brief 左平衡旋转处理代码
 *
 * @param tree
 */
void LeftBalance(AvlTree *tree)
{
    AvlTree lTree;       // 左子树
    AvlTree lTreeRChild; // 左子树的右子树
    lTree = (*tree)->lchild;
    switch (lTree->bf)
    {
    // 本来就是左子树高，继续左高，这是最容易处理的情况
    case LH:
        (*tree)->bf = EH; // 完全平衡 bf从2 -> 0
        lTree->bf = EH;   // 完全平衡 bf从1 -> 0
        R_Rotate(tree);   // 右旋操作
        break;
    // 插入的子节点在右侧
    case RH:
        lTreeRChild = lTree->rchild;
        switch (lTreeRChild->bf)
        {
        case LH:
            (*tree)->bf = RH;
            lTree->bf = EH;
            break;
        case EH:
            // 其实几乎没有这种情况，LH和RH就处理了
            (*tree)->bf = EH;
            lTree->bf = EH;
            break;
        case RH:
            (*tree)->bf = EH;
            lTree->bf = LH;
            break;
        default:
            printf("Error of %s in %d\n", __func__, __LINE__);
            break;
        }
        lTreeRChild->bf = EH;
        L_Rotate(&lTree);
        R_Rotate(tree);
    default:
        break;
    }
}

/**
 * @brief
 *
 * @param tree
 */
void RightBalance(AvlTree *tree)
{
    AvlTree rTree;       // 右子树
    AvlTree rTreeLChild; // 右子树的左子树
    rTree = (*tree)->rchild;
    switch (rTree->bf)
    {
    // 本来就是右子树高，继续右高，这是最容易处理的情况
    case RH:
        (*tree)->bf = EH;
        rTree->bf = EH;
        L_Rotate(tree); // 左旋操作
        break;
    case LH:
        rTreeLChild = rTree->lchild;
        switch (rTreeLChild->bf)
        {
        case LH:
            (*tree)->bf = EH;
            rTree->bf = RH;
            break;
        case EH:
            (*tree)->bf = EH;
            rTree->bf = EH;
            break;
        case RH:
            (*tree)->bf = LH;
            rTree->bf = EH;
            break;
        default:
            printf("Error of %s in %d\n", __func__, __LINE__);
            break;
        }
        rTreeLChild->bf = EH;
        R_Rotate(&rTree); // 右旋操作
        L_Rotate(tree);   // 左旋操作
    default:
        break;
    }
}

/**
 * @brief Avl树插入节点
 * 
 */
int InsertAVL(AvlTree *tree, int x, int *height)
{
    if (*tree == NULL)
    {
        *tree = CreateNode(x);
        *height = 0;
        return 1;
    }
    else if (x < (*tree)->data)
    {
        if (InsertAVL(&(*tree)->lchild, x, &(*tree)->lchild_height) == 1)
        {
            (*tree)->bf = (*tree)->lchild_height - (*tree)->rchild_height;
            LeftBalance(tree);
        }
    }
    else if (x > (*tree)->data)
    {
        if (InsertAVL(&(*tree)->rchild, x, &(*tree)->rchild_height) == 1)
        {
            (*tree)->bf = (*tree)->lchild_height - (*tree)->rchild_height;
            RightBalance(tree);
        }
    }
    else
    {
        printf("Error of %s in %d\n", __func__, __LINE__);
        return 0;
    }
    *height = (*tree)->lchild_height > (*tree)->rchild_height ? (*tree)->lchild_height : (*tree)->rchild_height;
    return 1;
    }
}