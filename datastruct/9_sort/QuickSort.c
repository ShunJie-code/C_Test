#include "common_9.h"

void QuickSort(SqList *L, int low, int high)
{
    if (low < high)
    {
        int pivot = L->r[low]; // 选择第一个元素作为基准
        int i = low;
        int j = high;

        while (i < j)
        {
            while (i < j && L->r[j] >= pivot)
                j--;
            if (i < j)
                L->r[i++] = L->r[j];

            while (i < j && L->r[i] <= pivot)
                i++;
            if (i < j)
                L->r[j--] = L->r[i];
        }
        L->r[i] = pivot; // 将基准放到正确的位置

        QuickSort(L, low, i - 1);  // 对左子序列递归排序
        QuickSort(L, i + 1, high); // 对右子序列递归排序
    }
}


