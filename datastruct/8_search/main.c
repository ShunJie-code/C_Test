/**
 * 第8章 查找算法
 * 70 查找算法
 * 71 插值查找
 * 72 斐波那契查找
 * 73 线性索引查找
 * 74 二叉排序树：插入和删除和查找的效率都非常高
 * 75 二叉排序树的查找插入、删除
 * 76 AVL树
 */
#include <stdio.h>
#include <stdlib.h>
#include "common_8.h"
#include "search.h"
#include "binarySortTree.h"

typedef void (*TestFunc)(void);

// 8.3 顺序查找/线性查找
void Test0(void)
{
    int a[] = {0, 1, 2, 3, 4, 5}; // 注意 0 查找不到，a[0]不存值
    int key = 8;
    ShowTimeStamp();
    int index = SqSearch(a, sizeof(a) / sizeof(int) - 1, key);
    CheckSearchResult(index, key);
    key = 5;
    index = SqSentinelSearch(a, sizeof(a) / sizeof(int) - 1, key);
    CheckSearchResult(index, key);
    ShowTimeStamp();
}

// 8.4 有序表查找
void Test1(void)
{
    int a[] = {0, 1, 2, 3, 4, 5, 10, 100}; // 注意 0 查找不到，a[0]不存值
    int key = 1;
    int index = BinarySearch(a, sizeof(a) / sizeof(int) - 1, key);
    CheckSearchResult(index, key);
    key = 10;
    index = InterpolationSearch(a, sizeof(a) / sizeof(int) - 1, key);
    CheckSearchResult(index, key);
    printf("%s\n", __func__);
}

// 8.5 线性索引查找
void Test2(void)
{
    printf("%s\n", __func__);
}

// 8.6 二叉排序树
void Test3(void)
{
    BiTree bTree = NULL;  // 必须要定义一个空树
    BiTNode *p = NULL;
    int iSearchValue = 12;
    BST_Inseart(&bTree, 10);
    BST_Inseart(&bTree, 13);
    BST_Inseart(&bTree, 9);
    BST_Inseart(&bTree, 12);
    BST_Inseart(&bTree, 8);
    PreOrderTraverse(bTree, 0);
    bool bSearchOk = BST_Search(bTree, iSearchValue, NULL, &p);
    printf("search %d is %d, p->data = %d\n", iSearchValue, bSearchOk, p->data);
    printf("%s finish\n", __func__);
}

void Test4(void)
{
    printf("%s 二叉排序树删除\n", __func__);
    BiTree bTree = NULL;  // 必须要定义一个空树
    int arr[] = {62, 58, 47, 35, 29, 37, 36, 51, 49, 48,
                50, 56, 88, 73, 99, 93};
    int len = sizeof(arr) / sizeof(int);
    BST_Create(&bTree, arr, len);
    printf("origin:\n");
    LevelOrderTraverse(bTree);

    BST_Delete(&bTree, 47);
    printf("after delete 47:\n");
    LevelOrderTraverse(bTree);

    BST_Delete(&bTree, 62);
    printf("after delete 62:\n");
    LevelOrderTraverse(bTree);
    printf("%s 二叉排序树删除，测试完成\n", __func__);
}

void Test5(void)
{
    printf("%s\n", __func__);
}

int main(int argc, char* argv[])
{
    int testNum = -1;
    int testLength;
    TestFunc testFunc[] = {Test0, Test1, Test2,
                           Test3, Test4, Test5};
    testLength = sizeof(testFunc) / sizeof(TestFunc);

    for (int i = 0; i < argc; i++)
    {
        // printf("The %d param is %s\n", i, argv[i]); // The 0 param is ./main
        if (i >= 1)
        {
            testNum = atoi(argv[i]);
            if (testNum >= 0 && testNum < testLength)
                testFunc[testNum]();
            else
                printf("Please enter a correct test number, max is %d\n", testLength);
        }
    }
    return 0;
}