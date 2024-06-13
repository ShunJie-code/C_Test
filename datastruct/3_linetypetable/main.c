/**
 *                顺序存储 链式存储
 * 查找            O(1)    O(n)
 * 插入和删除       O(n)    O(1)
 * 空间性能        预分配   动态申请
 * 频繁的查找       优      差
 * 频繁的插入删除    差      优
*/

#include <stdio.h>
#include <stdlib.h>

#include "Sqlist.h"                 // 顺序存储结构线性表
#include "Linklist.h"               // 链式存储结构线性表
#include "StaticLinklist.h"         // 静态链表
#include "CirLL.h"                  // 循环链表
#include "DoubLinkList.h"           // 双向链表

// 1 测试顺序结构线性表基础功能
void Test1(void)
{
    printf("%d-%s:\n", __LINE__, __func__);
    SqList ls;
    Status ret;
    ElemType e;
    int arr1[10] = {0, 1, 2, 3, 6, 5, 4, 9, 8, 7};

    ret = InitList(&ls, arr1, 10);
    ret = GetElem(ls, 10, &e);
    if (ret == OK)
        printf("ls 10th data = %d\n", e);
    else
        printf("Please check your param\n");
    ShowListData(ls);
    ret = ListInsert(&ls, 5, 999);
    if (ret == OK)
        ShowListData(ls);
    else
        printf("Please check your param\n");
    ret = ListDelete(&ls, 5, &e);
    if (ret == OK)
    {
        printf("Deleted data = %d\n", e);
        ShowListData(ls);
    }
    else
        printf("Please check your param\n");
}

// 2 测试两个线性表求并集
void Test2(void)
{
    printf("%d-%s:\n", __LINE__, __func__);
    Status ret;
    SqList ls1;
    SqList ls2;
    int arr1[10] = {0, 1, 2, 3, 6, 5, 4, 9, 8, 7};
    int arr2[5] = {9, 99, 100, 77, 6};
    printf("size of arr1 = %zd, arr2 = %zd\n", sizeof(arr1), sizeof(arr2));
    ret = InitList(&ls1, arr1, 10);
    ret = InitList(&ls2, arr2, 5);
    UnionL(&ls1, ls2);
    ShowListData(ls1);
}

// 3 测试链式结构线性表的基础功能 
void Test3(void)
{
    LinkList ll;
    ElemType e;
    // ll = NULL; // 注释后，不会malloc，因为头结点已经存在了,与80行同在
    LinkListInitHead(&ll, 10);

    LinkListShow(ll);
    LinkListInsert(&ll, 5, 99);
    LinkListInsert(&ll, 8, 88);
    LinkListShow(ll);

    LinkListDelete(&ll, 7, &e);
    printf("Deleted 7th data = %d\n", e);
    LinkListShow(ll);

    LinkGetElem(ll, 9, &e);
    printf("9th data = %d\n", e);

    LinkListClear(&ll);
    LinkListShow(ll);

    LinkListInitTail(&ll, 13);
    LinkListShow(ll);

    LinkListClear(&ll);
    // free(ll);  // free(): invalid pointer，这里不需要free，函数结束即释放，与58行同在
}

// 4 测试链表的头插法\尾插法\清空\找中间节点等API
static void Test4(void)
{
    LinkList ll_t;
    LinkList ll;
    ElemType e;
    ll = NULL;
    ll_t = NULL;

    LinkListInitTail(&ll, 7);
    LinkListShow(ll);
    LinkGetMidNode(ll, &e);
    printf("mid of ll = %d\n", e);
    LinkListInitHead(&ll_t, 10);
    LinkGetMidNode(ll_t, &e);
    printf("mid of ll_t = %d\n", e);
    LinkListShow(ll_t);

    LinkListClear(&ll);
    LinkListClear(&ll_t);
    free(ll_t);
    free(ll);
}

// 5 测试静态链表API
static void Test5(void)
{
    int len;
    int array[6] = {1, 2, 3, 4, 5, 6}; 
    StaticLinkList sll;

    SLL_Init(sll);
    SLL_Create(sll, array, 6);
    SLL_Show(sll);
    SLL_Insert(sll, 3, 99);
    SLL_Insert(sll, 8, 96);
    SLL_Insert(sll, 1, 98);

    SLL_Show(sll);
    SLL_Delete(sll, 5);
    SLL_Delete(sll, 3);
    SLL_Show(sll);
    len = SLL_Length(sll);
    printf("SLL len = %d\n", len);
}

// 6 测试循环链表，约瑟夫问题
static void Test6(void)
{
    // Josephus();
    CLL_App();
}

// 7 测试双向链表，凯撒问题
static void Test7(void)
{
    DuLinkList dll;
    DLL_Init(&dll);
    DLL_ShowList(dll);
    Caesar(&dll, 3);
    DLL_ShowList(dll);
    Caesar(&dll, -5);
    DLL_ShowList(dll);
}

int main(void)
{
    // Test1();
    // Test2();
    // Test3();
    // Test4();
    // Test5();
    // Test6();
    Test7();
    return 0;
}

