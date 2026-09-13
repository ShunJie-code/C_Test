#include <stdio.h>
#include <stdlib.h>
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
        L_Rotate(&(*tree)->lchild);  // L_Rotate(&lTree);操作的并不是原来指针的地址哦
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
        R_Rotate(&(*tree)->rchild); // R_Rotate(&rTree); 右旋操作; 这样写是错误的，操作的局部的指针
        L_Rotate(tree);   // 左旋操作
    default:
        break;
    }
}

/**
 * @brief Avl树插入节点
 * 如果在树中不存在该节点才插入；存在则返回FALSE
 * taller 表示是否插入成功，树长高了
 */
int AVL_Insert(AvlTree *tree, int e, int *taller)
{
    if (*tree == NULL)
    {
        // 1 树为空，直接插入根节点
        *tree = (AvlTNode *)malloc(sizeof(AvlTNode));
        (*tree)->data = e;
        (*tree)->lchild = NULL;
        (*tree)->rchild = NULL;
        (*tree)->bf = EH;
        *taller = TRUE;
    }
    else
    {
        // 2 值相同，不插入
        if (e == (*tree)->data)
        {
            *taller = FALSE;
            return FALSE;
        }
        // 3 插入左子树
        if (e < (*tree)->data)
        {
            // 4 递归插入左子树
            if (AVL_Insert(&(*tree)->lchild, e, taller) == FALSE)
                return FALSE;
            // 5 插入后，判断是否需要平衡
            if (*taller)
            {
                switch ((*tree)->bf)
                {
                case LH:
                    // 原本左子树高，插入之后大于LH，需要左旋
                    LeftBalance(tree);
                    *taller = FALSE;
                    break;
                case EH:
                    (*tree)->bf = LH;
                    *taller = TRUE;
                    break;
                case RH:
                    // 原本右子树高，插入之后等高
                    (*tree)->bf = EH;
                    *taller = FALSE;
                    break;
                default:
                    printf("Error of %s in %d\n", __func__, __LINE__);
                    break;
                }
            }
        }
        else
        {
            if (AVL_Insert(&(*tree)->rchild, e, taller) == FALSE)
                return FALSE;     // 值已经存在，不插入
            if (*taller)
            {
                switch ((*tree)->bf)
                {
                 case LH:
                    (*tree)->bf = EH;
                    *taller = FALSE;
                    break;
                case EH:
                    (*tree)->bf = RH;
                    *taller = TRUE;
                    break;
                case RH:
                    // 原本右子树高，插入之后大于RH，需要右旋
                    RightBalance(tree);
                    *taller = FALSE;
                    break;
                default:
                    printf("Error of %s in %d\n", __func__, __LINE__);
                    break;
                }
            }
        }
    }
    return TRUE;
}

void AVL_LevelOrderTraverse(AvlTree root)
{
    if (root == NULL)
        return;

    // 用数组模拟队列
    AvlTNode *queue[1000];
    int front = 0, rear = 0;

    // 根节点入队
    queue[rear++] = root;

    while (front < rear)
    {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++)
        {
            // 出队
            AvlTNode *cur = queue[front++];
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