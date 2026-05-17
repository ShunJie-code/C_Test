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
#include <stdbool.h>
// Binary sort tree 二叉排序树、节点的结构定义
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/**
 * @brief 创建二叉排序树
 * 
 * @param T 
 * @param arr 
 * @param len 
 * @return true 
 * @return false 
 */
bool BST_Create(BiTree *T, int arr[], int len);

/**
 * @brief 查找操作-递归查找二叉排序树T中是否存在key
 * @param T 树根、递归的节点
 * @param key 要查找的值
 * @param f 指针f指向T的双亲，初始调用值为null
 * @param p key值的节点位置或最接近key值的节点位置的指针
 * @return true 若查找成功，则指针p指向该数据元素结点，并返回true
 * @return false 否则p指向查找路径上访问的最后一个结点，并返回false
 */
bool BST_Search(BiTree T, int key, BiTNode *f, BiTNode **p);


/**
 * @brief 插入操作-当二叉排序树中不存在关键字为key的数据元素时，插入key返回true，否则返回false
 * 
 * @param T 指向树根的指针
 * @param key 待插入的值
 * @return true 插入key值，返回true
 * @return false key已经存在了，没插入，返回false
 */
bool BST_Inseart(BiTree *T, int key);

/**
 * @brief 树的前序遍历
 * 
 * @param T 
 * @param level 
 */
void PreOrderTraverse(BiTree T, int level);


void LevelOrderTraverse(BiTree root);

/**
 * @brief 若二叉树T中存在关键字等于Key的数据元素时，则删除该数据元素节点
 * 并返回TRUE,否则返回FALSE
 * 
 * @param tree 
 * @param key 
 * @return true 
 * @return false 
 */
bool BST_Delete(BiTree *tree, int key);

#endif