#include "avl_tree.h"
/**
 * @brief 右旋操作
 * 
 * @param p 
 */
void R_Rotate(AvlTree *p)
{
    AvlTree lTree;
    lTree = (*p)->lchild;           // 1 拿到左子树
    (*p)->lchild = lTree->rchild;   // 2 将左子树的右节点，移动到根节点的左侧
    lTree->rchild = (*p);           // 3 根节点作为左子树的右节点
    *p = lTree;                     // 4 更新树的根节点
}

void L_Rotate(AvlTree *p)
{
    AvlTree rTree;
    rTree = (*p)->rchild;           // 1 拿到右子树
    (*p)->rchild = rTree->lchild;   // 2 将右子树的左节点，移动到根节点的右侧
    rTree->lchild = (*p);           // 
    *p = rTree;  
}

/**
 * @brief 
 * 
 * @param tree 
 */
void LeftBalance(AvlTree *tree)
{

}

/**
 * @brief 
 * 
 * @param tree 
 */
void RightBalance(AvlTree *tree)
{
    
}