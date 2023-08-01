/**
 * @file P37_dm.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 动态内存管理1
 * @version 0.1
 * @date 2023-08-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>

void Test1()
{
    int *ptr;
    ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL)
    {
        printf("Malloc Fail!\n");
        exit(1);
    }
    printf("Please enter an int: ");
    scanf("%d", ptr);
    printf("You enter int is: %d\n", *ptr);
    
    free(ptr);
}

int main()
{
    Test1();
    return 0;
}