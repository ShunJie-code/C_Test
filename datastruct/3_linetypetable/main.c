#include <stdio.h>
#include "Sqlist.h"
#include "Linklist.h"

// 测试顺序结构线性表基础功能
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

// 测试两个求并集
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

void Test3(void)
{
    LinkList ll;
    ElemType e;
    LinkListInitHead(&ll, 10);

    LinklistShow(ll);
    LinkListInsert(&ll, 5, 99);
    LinklistShow(ll);
    LinkGetElem(ll, 9, &e);
    printf("9th data = %d\n", e);
    LinkListClear(&ll);
    LinklistShow(ll);
}

int main(void)
{
    // Test1();
    // Test2();
    Test3();
    return 0;
}

