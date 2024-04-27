/**
 * p7-8 线性表的抽象数据类型
 * Operation
 *   InitList(*L)          ： 初始化线型表
 *   GetElem(L, i, *e)     :  查找线性表第i个参数的值
 *   ListInsert(*L, i, e)  :  在L中第i个位置之前插入新的数据元素e，L长度+1
 *   ListDelete(*L, i, *e) :  删除L的第i个数据元素，并用e返回其值，L的长度-1
 * 
 * Debug
 *   ShowListData(L)      :   展示线性表的数据
*/
#include <stdio.h>
#include <string.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;               // 线性表当前的长度
}SqList;

void ShowListData(SqList l)
{
    printf("List data: ");
    for (int i = 0; i < l.length; i++)
    {
        printf("%4d  ", l.data[i]);
    }
    putchar('\n');
}

Status InitList(SqList *l)
{
    int n = 10;
    int arr[10] = {0, 1, 2, 3, 6, 5, 4, 9, 8, 7};
    l->length = n;
    memcpy(l->data, arr, sizeof(arr));
    return OK;
}
 
Status GetElem(SqList l, int i, ElemType *e)
{
    // 输入参数，合法性检测
    if (l.length == 0 || i < 1 || i > l.length)
    {
        return ERROR;
    }
    *e = l.data[i - 1];
    return OK;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;
    // 1 线性表已满不能再插入检测
    if (L->length == MAXSIZE)           
    {
        return ERROR;
    }
    // 2 插入的位置非法校验
    if (i < 1 || i > L->length + 1)
    {
        return ERROR;
    }
    // 3 数据移动
    if (i <= L->length)
    {
        for (k = L->length - 1; k >= i - 1; k--)
        {
            L->data[k + 1] = L->data[k];
        }
    }
    // 4 数据赋值
    L->data[i - 1] = e;
    // 5 长度更新
    L->length++;
    return OK;
}

Status ListDelete(SqList *l, int i, ElemType *e)
{
    int k;
    if (l->length == 0)
    {
        return ERROR;
    }
    if (i < 1 || i > l->length)
    {
        return ERROR;
    }
    *e = l->data[i - 1];
    if (i < l->length)
    {
        for (k = i; k < l->length; k++)
        {
            l->data[k - 1] = l->data[k];
        }
    }
    l->length--;
    return OK;
}

int main(void)
{
    SqList ls;
    Status ret;
    ElemType e;
    ret = InitList(&ls);
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
    return 0;
}
