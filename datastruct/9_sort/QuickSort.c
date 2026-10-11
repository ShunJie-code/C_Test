#include "common_9.h"

/**
 * @brief 两端搜索排序
 * 
 * @param sq 
 * @param low 
 * @param high 
 * @return int 返回枢轴的位置 
 */
int Partition(SqList *sq, int low, int high)
{
    int pivotkey;
    pivotkey = sq->r[low];
    while (low < high)
    {
        // 搜索高
        while (low < high && sq->r[high] >= pivotkey)  // 一旦小就退出
        {
            high--;
        }
        swap(sq, low, high);
        // 搜索低
        while (low < high && sq->r[low] <= pivotkey)
        {
            low++;
        }
        swap(sq, low, high);
    }
    return low;
}

void QuickSort(SqList *sq, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(sq, low, high);
        QuickSort(sq, low, pivot - 1);  // 对左子序列递归排序
        QuickSort(sq, pivot + 1, high); // 对右子序列递归排序
    }
}

void QSort(SqList *sq)
{
    QuickSort(sq, 1, sq->length);
}
