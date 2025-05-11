// 将结构体与函数用头文件封装好
// 对顺序表L作简单选择排序

#include "common_9.h"

void SelectSort(SqList *L)
{
    int i, j, min;
    for (i = 1; i < L->length; i++)
    {
        min = i; // 每一次循环min都要定义到开始位
        for (j = i + 1; j <= L->length; j++)
        {
            if (L->r[min] > L->r[j])
                min = j;
        }
        if (i != min)
            swap(L, i, min);
    }
}
