/**
 * @file p42_struct.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 结构体
 * @version 0.1
 * @date 2023-08-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

struct Book
{
    char title[128];
    char author[40];
    float price;
    unsigned int data;
    char publisher[40];
};
// 大小为8
struct A
{
    char a;
    char c;
    int b;
};
// 大小为12
// struct A
// {
//     char a;
//     int b;
//     char c;
// };

void Test1(void)
{
    struct Book book;
    printf("Please enter the title:");
    scanf("%s", book.title);
    printf("Please enter the author:");
    scanf("%s", book.author);
    printf("Please enter the price:");
    scanf("%f", &book.price);
    printf("Please enter the data:");
    scanf("%d", &book.data);
    printf("Please enter the publisher:");
    scanf("%s", book.publisher);

    printf("===ok===\n");
    printf("Book's title: %s\n", book.title);
    printf("Book's author: %s\n", book.author);
    printf("Book's price: %f\n", book.price);
    printf("Book's data: %d\n", book.data);
    printf("Book's publisher: %s\n", book.publisher);

}

void Test2(void)
{
    struct A a = {'x', 'j', 520};
    printf("size of a = %d\n", sizeof(a));// 内存对齐
}

int main()
{
    Test1();
    Test2();
    return 0;
}