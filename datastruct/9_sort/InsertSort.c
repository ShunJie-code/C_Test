/*对循序表L作直接插入排序*/
#include "common_9.h"

void InsertSort(SqList *L)
{
    int i, j;
    for (i = 2; i <= L->length; i++)
    {
        if (L->r[i - 1] > L->r[i])
        {
            L->r[0] = L->r[i]; // 用零位临时存储要插入的r[i]
            for (j = i - 1; L->r[j] > L->r[0]; j--)
            {
                L->r[j + 1] = L->r[j]; // 记录后移
            }
            L->r[j + 1] = L->r[0];
        }
    }
}