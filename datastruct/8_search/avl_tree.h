/**
 * @file avl_tree.h
 * @author your name (you@domain.com)
 * @brief 平衡二叉树的意义在于普通二叉树是斜树时，搜索时间复杂度依旧是O[n]
 *         ALV 树的时间复杂度是O[log2(n)]
 * @version 0.1
 * @date 2026-06-19
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef AVL_TREE_H
#define AVL_TREE_H

#define LH (1)   // 左子树高
#define EH (0)
#define RH (-1)  // 右子树高
// 概念1 平衡因子BF,左子树深度减去右子树深度
typedef struct AvlTNode
{
    int data;
    // 平衡因子；左子树深度减去右子树深度
    int bf;
    struct AvlTNode *lchild, *rchild;
}AvlTNode, *AvlTree;


// euru

#endif