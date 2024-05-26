/**
 * p14 静态链表，核心是数组内数据快速插入和删除，通过cur来索引
 * p15 静态链表内存申请和释放,插入与删除
 * p16 静态链表的总结，给没有指针的编程语言一种实现方法
 */
#include <stdio.h>

#include "StaticLinklist.h"

Status SLL_Init(StaticLinkList space)
{
    int i;
    for (i = 0; i < MAXSIZE - 1; i++)    
    {
        space[i].cur = i + 1;            // 当前数据的游标等于下一个数据的下标，刚开始数据为空，所以0位置的游标为1
    }
    space[MAXSIZE - 1].cur = 0;          
    return OK;
}

Status SLL_Create(StaticLinkList sll, int *arr, uint32_t size)
{
    if (size > MAXSIZE)
    {
        return ERROR;
    }
    
    for (int i = 0; i < size; i++)
    {
        sll[i + 1].data = arr[i];
    }
    sll[0].cur = size + 1;              // 第一个位置的cur存放备用链表第一个节点的下标
    sll[size].cur = 0;                  // 下一个元素的数据为空则，next为0
    sll[MAXSIZE -1].cur = 1;            // 最后一个位置的游标存放第一个插入元素的下标
    return OK;
}

void SLL_Show(StaticLinkList sll)
{
    int i;
    i = sll[MAXSIZE - 1].cur;
    printf("SLL data: ");
    while (i)
    {
        printf("%d, ", sll[i].data);
        i = sll[i].cur;
    }
    putchar('\n');
}

/**
 * 手动实现malloc和free
 */
static int SLL_Malloc(StaticLinkList space)     // 获取空闲分量的下标
{
    int i = space[0].cur;                // 找出待插入位置
    if (space[0].cur)
        space[0].cur = space[i].cur;     // 第一个元素的游标指向下一个空闲分量的下标，备用
    return i;
}
// 要将删除的位置加入备用链表
static void SLL_Free(StaticLinkList space, int k)
{ 
    space[k].cur = space[0].cur;        // 为了是后续的空数据下标也能连续起来
    space[0].cur = k;                   // 备用链表指向k
}
/**
 * 插入元素
*/
Status SLL_Insert(StaticLinkList sll, int i, ElemType e)
{
    int j, k, l;
    k = MAXSIZE - 1;
    if (i < 1 || i > SLL_Length(sll) + 1)
    {
        return ERROR;
    }
    j = SLL_Malloc(sll);
    if (j)
    {
        sll[j].data = e;
        for (l = 1; l < i; l++)
        {
            k = sll[k].cur;
        }
        sll[j].cur = sll[k].cur;
        sll[k].cur = j;
        return OK;
    }
    return ERROR;
}

Status SLL_Delete(StaticLinkList sll, int i) // 删除元素
{
    int j, k;
    if (i < 1 || i > SLL_Length(sll))
    {
        return ERROR;
    }
    k = MAXSIZE - 1;
    for (j = 1; j <= i - 1; j++)
    {
        k = sll[k].cur;                     // 前一个元素
    }
    j = sll[k].cur;                         // 找到要删的位置
    sll[k].cur = sll[j].cur;                // 前一个元素指向下一个元素
    SLL_Free(sll, j);
    return OK;
}

/*返回L中数据元素个数*/
int SLL_Length(StaticLinkList L)
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
