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
#include <string.h>

void Test1()
{
    int *ptr;
    ptr = (int *)malloc(sizeof(int));
    printf("%p\n", ptr);

    if (ptr == NULL)
    {
        printf("Malloc Fail!\n");
        exit(1);
    }
    printf("Please enter an int: ");
    scanf("%d", ptr);
    printf("You enter int is: %d\n", *ptr);
    
    free(ptr);

    printf("%p\n", ptr);
}
// 全局变量指向堆测试
static char *str = NULL;
void Test2()
{
    printf("%p\n", str);
    str = (char *)malloc(10);
    if (str == NULL)
    {
        printf("Malloc failed!\n");
        exit(1);
    }
    char *strEng = "abcdefg";
    memcpy(str, strEng, strlen(strEng));
}
void Test3()
{
    printf("%s\n", str);
    free(str);
    printf("%p\n", str);
}

int main()
{
    Test1();
    Test2();
    Test3();
    return 0;
}