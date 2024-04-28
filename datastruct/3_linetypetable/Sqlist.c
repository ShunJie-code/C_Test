/**
 * p7 线性表抽象数据类型
 * p8 线性表的顺序存储结构
 * p9 线性表顺序存储结构的优缺点
 * Operation
 *   InitList(*L)          ： 初始化线型表
 *   GetElem(L, i, *e)     :  查找线性表第i个参数的值
 *   ListInsert(*L, i, e)  :  在L中第i个位置之前插入新的数据元素e，L长度+1
 *   ListDelete(*L, i, *e) :  删除L的第i个数据元素，并用e返回其值，L的长度-1
 *   LocateElem(L, e)      :  查找成功则返回e首次出现的序号（从1开始），不存在则返回 FALSE
 * 对于不同的应用，线性表的基本操作是不同的，但上述操作是最基本的，
 * 复杂的应用可以用基本操作组合来实现。
 * 比如实现两个线性表A、B的并集操作：UnionL(*L, L)
 * Debug
 *   ShowListData(L)      :   展示线性表的数据
*/
#include <stdio.h>
#include <string.h>
#include "Sqlist.h"

void ShowListData(SqList l)
{
    printf("List data: ");
    for (int i = 0; i < l.length; i++)
    {
        printf("%4d  ", l.data[i]);
    }
    putchar('\n');
}

int LocateElem(SqList l, int e)
{
    for (int i = 0; i < l.length; i++)
    {
        if (e == l.data[i])
        {
            return i + 1;
        }
    }
    return FALSE;
}

Status InitList(SqList *l, int *arr, int len)
{
    if (len > MAXSIZE || arr == NULL)
    {
        return ERROR;
    }
    
    l->length = len;
    memcpy(l->data, arr, sizeof(ElemType) * len);
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

void UnionL(SqList *La, SqList Lb)
{
    int La_len, Lb_len, i;
    ElemType e;
    La_len = La->length;
    Lb_len = Lb.length;

    for (i = 1; i <= Lb_len; i++)
    {
        GetElem(Lb, i, &e);
        // 找不到输出为0，取反为1，即可插入该值
        if (!LocateElem(*La, e)) {   
            ListInsert(La, ++La_len, e);
        }
    }
}
