/**
 *  p14 静态链表
 */
#include "StaticLinklist.h"

Status InitList(StaticLinkList space)
{
    int i;
    for (i = 0; i < MAXSIZE - 1; i++)    // 第一个位置的cur存放备用链表第一个节点的下标
    {
        space[i].cur = i + 1;            // 当前数据的游标等于下一个数据的下标，刚开始数据为空，所以0位置的游标为1
    }
    space[MAXSIZE - 1].cur = 0;          // 最后一个元素的游标存放第一个插入元素的下标
    return OK;
}
/**
 * 手动实现malloc
 */
int Malloc_SLL(StaticLinkList space)     // 获取空闲分量的下标
{
    int i = space[0].cur;                // 找出待插入位置
    if (space[0].cur)
        space[0].cur = space[i].cur;     // 第一个元素的游标指向下一个空闲分量的下标，备用
    return i;
}

/**
 * 插入元素
*/
Status ListInsert(StaticLinkList L, int i, ElemType e) 
{
    int j, k, l;
    k = MAXSIZE - 1;
    if (i < 1 || i > ListLength(L) + 1)
    {
        return ERROR;
    }
    j = Malloc_SLL(L);
    if (j)
    {
        L[j].data = e;
        for (l = 1; l <= i - 1; l++)
        {
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}

Status ListDelete(StaticLinkList L, int i) // 删除元素
{
    int j, k;
    if (i < 1 || i > ListLength(L))
    {
        return ERROR;
    }
    k = MAXSIZE - 1;
    for (j = 1; j <= i - 1; j++)
    {
        k = L[k].cur; // 前一个元素
    }
    j = L[k].cur;        // 找到要删的位置
    L[k].cur = L[j].cur; // 前一个元素指向下一个元素
    Free_SLL(L, j);
    return OK;
}

void Free_SLL(StaticLinkList space, int k)
{ // 要将删除的位置加入备用链表
    space[k].cur = space[0].cur;
    space[0].cur = k;
}
/*返回L中数据元素个数*/
int ListLength(StaticLinkList L)
{
    int j = 0;
    int i = L[MAXSIZE - 1].cur;
    while (i)
    {
        i = L[i].cur;
        j++;
    }
    return j;
}