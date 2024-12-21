/**
 * 第8章 查找算法
 * 70 顺序查找
 */
#include <stdio.h>
#include "search.h"

int main(void)
{
    int key = 8;
    int a[5] = {1, 2, 3, 4, 5};

    int index = SQ_Search(a, 5, key);
    if (index != 0)
        printf("Element %d index is %d\n", key, index);
    else
        printf("Element %d is not found\n", key);
    return 0;
}