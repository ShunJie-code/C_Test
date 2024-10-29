// 第6章 树

/**
 * 41 树的基本概念
 * linux操作系统就是树结构
 * 42 树的存储结构-双亲表示法
 * 43 树的存储结构-孩子表示法
 * 44 二叉树1
 * 45 二叉树2
 * 46 二叉树的存储结构
 * 47 二叉树的遍历
 */
#include "common_6.h"

#define MAX_TREE_SIZE 100
/* 树的双亲表示法 */typedef struct PTNode
{
    ElemType data;                   // 节点数据
    int parent;                      // 双亲位置，根双亲为-1
} PTNode;

typedef struct 
{
    PTNode nodes[MAX_TREE_SIZE];
    int r;                           // 根的位置
    int n;                           // 节点数目
};

/**
 * 孩子表示法，度不一致，初始化和维护起来难度巨大
 */

/**
 * 双亲孩子表示法
 */

// 孩子节点
typedef struct CTNode
{
    int child;              // 孩子节点的下标
    struct CTNode *next;
} *ChildPtr;

// 表头结构
typedef struct 
{
    ElemType data;         // 数据
    int parent;
    ChildPtr firstChild;
} CTBox;

// 树结构
typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];  // 节点数组
    int r, n;
};
