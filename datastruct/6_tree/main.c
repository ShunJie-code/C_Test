// 第6章 树

/**
 * 41 树的基本概念-linux操作系统就是树结构
 * 42 树的存储结构-双亲表示法
 * 43 树的存储结构-孩子表示法
 * 44 二叉树1
 * 45 二叉树2
 * 46 二叉树的存储结构
 * 47 二叉树的遍历
 * 48 二叉树的建立和遍历
 * 49 线索二叉树，中序遍历+线索或者节点
 * 50 线索二叉树的实现
 * 51 树、森林及二叉树的相互转换
 */
#include <stdio.h>
#include "common_6.h"

#define MAX_TREE_SIZE 100

/* 1 树的双亲表示法--用顺序存储结构数组的形式表示树 */
typedef struct PTNode
{
    IntElemType data;                   // 节点数据
    int parent;                         // 双亲位置，根双亲为-1
    int rightsib;                       // ！！！改进：树的双亲右兄弟表示法 ！！！
} PTNode;

typedef struct 
{
    PTNode nodes[MAX_TREE_SIZE];
    int r;                              // 根的位置，通常是0
    int n;                              // 节点数目
} PTree;

/* 2 树的孩子表示--应对度不一致，初始化和维护起来复杂度大的树 */
typedef struct CTNode                   
{
    int child;                          // 孩子节点的下标
    struct CTNode *next;                // 将每个节点的孩子节点排列起来作为单链表
} *ChildPtr;                            // 2.1 节点

typedef struct                          
{
    IntElemType data;                   // 节点数据
    int parent;                         // ！！！改进双亲孩子表示法
    ChildPtr firstChild;
} CPTBox;                               // 2.2 表头结构 

typedef struct
{
    CPTBox nodes[MAX_TREE_SIZE];
    int r, n;
} CPTree;                                // 2.3 树结构

void test1(void)
{
    int level = 1;
    BiTree biTree = NULL;
    printf("请按前序遍历输入一颗树：\n");
    CreateBiTree(&biTree);                      // 教程上的树ABDG##H###CE#I##F##
    printf("前序遍历：\n");
    PreOrderTraverse(biTree, level);
    printf("中序遍历：\n");
    InOrderTraverse(biTree, level);
    printf("后序遍历：\n");
    PostOrderTraverse(biTree, level);
    DestroyBiTree(biTree);
}

void test2(void)
{
    BiThreadNode *pHead;
    BiThreadTree tree = NULL;
    CreateBiThreadTree(&tree);  // ABC  D  E F    
    InOrderThread(&pHead, tree);
    THR_InOrderTraverse(pHead); // 中序遍历CBDAEF
    printf("\nfinish\n");
}

int main(void)
{
    // test1();
    test2();
    return 0;
}
