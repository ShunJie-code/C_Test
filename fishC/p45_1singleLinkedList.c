/**
 * @file p45_1singleLinkedList.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 单链表
 * @version 0.1
 * @date 2023-08-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
struct Book
{
    char title[128];
    struct Book *next;
};

void AddBook(struct Book **library)
{
    struct Book *book;
    book = (struct Book *)malloc(sizeof(struct Book));
    if (book == NULL)
    {
        printf("Fail to malloc memmory!\n");
        exit(1);
    }
}
void Test1(void)
{
    struct Book *library
}

int main()
{

}