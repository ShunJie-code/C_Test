/**
 * @file p36_sort.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 排序算法-quick_sort
 * @version 0.1
 * @date 2023-11-16
 * 
 * @copyright Copyright (c) 2023
 * 核心思想是递归+二分
 */
#include <stdio.h>
void QuickSort(int array[], int left, int right)
{
    int i = left;
    int j = right;
    int temp;
    int pivot;
    pivot = array[(left + right) / 2];
    while (i <= j)
    {
        // 从左到右找到大于等于基准点的元素, 尽快的让等于基准的元素往基准靠齐
        while (array[i] < pivot)
        {
            i++;
        }
        // 从右到左找到小于等于基准点的元素
        while (array[j] > pivot)
        {
            j--;
        }
        // 如果i <= j则互换元素
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) {
        QuickSort(array, left, j);
    }
    if (i < right) {
        QuickSort(array, i, right);        
    }
}

void Test1(void)
{
    int array[] = {73, 108, 111, 118, 101, 70, 105, 115, 104, 67, 46, 99, 111, 109};
    int i, length;
    length = sizeof(array) / sizeof(array[0]);
    QuickSort(array, 0, length - 1);
    printf("Result:\n");
    for (i = 0; i < length; i++)
    {
        printf("%d\t", array[i]);
    }
    putchar('\n');
}

int main(void)
{
    Test1();
    return 0;
}
