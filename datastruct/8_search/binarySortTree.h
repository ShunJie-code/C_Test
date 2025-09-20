/**
 * @file binarySortTree.h
 * @author your name (you@domain.com)
 * @brief 二叉排序树
 * @version 0.1
 * @date 2025-09-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef BINARY_SORT_TREE
#define BINARY_SORT_TREE

// Binary sort tree 二叉排序树、节点的结构定义
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/**
 * @brief 查找操作-递归查找二叉排序树T中是否存在key
 * @param T 
 * @param key 
 * @param f 指针f指向T的双亲，初始调用值为null
 * @param p 
 * @return true 若查找成功，则指针p指向该数据元素结点，并返回true
 * @return false 否则p指向查找路径上访问的最后一个结点，并返回false
 */
bool BST_Search(BiTree T, int key, BiTree f, BiTree *p);


/**
 * @brief 插入操作-当二叉排序树中不存在关键字为key的数据元素时
 * 
 * @param T 
 * @param key 
 * @return true 插入key返回true
 * @return false 否则返回false
 */
bool BST_Inseart(BiTree *T, int key);
#endif