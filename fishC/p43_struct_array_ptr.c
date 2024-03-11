/**
 * @file struct_array_ptr.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 结构体数组和指针
 * @version 0.1
 * @date 2023-08-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

struct Data
{
    int year;
    int month;
    int day;
};

struct Book
{
    char title[128];
    char author[40];
    float price;
    unsigned int data;
    char publisher[40];
};
struct Book1
{
    char title[128];
    char author[40];
    float price;
    // unsigned int data;
    struct Data data;
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
    printf("Book's data: %u\n", book.data);
    printf("Book's publisher: %s\n", book.publisher);

}

void Test2(void)
{
    struct A a = {'x', 'j', 520};
    printf("size of a = %d\n", sizeof(a));// 内存对齐
}

// 结构体嵌套
void Test3(void)
{
    struct Book1 book = {"FishC", "xsj", 48.8, {2023, 8, 16}, "chubanshe"};
    printf("Book title: %s\n", book.title);
    printf("Book author: %s\n", book.author);
    printf("Book author: %.2f\n", book.price);
    printf("Book data: %d/%d/%d\n", book.data.year, book.data.month, book.data.day);
    printf("Book Publisher: %s\n", book.publisher);
}
void Test4(void)
{
    struct Book1 book = {"FishC", "xsj", 48.8, {2023, 8, 16}, "chubanshe"};
    struct Book1 *ptr;
    ptr = &book;
    printf("Book title: %s\n", (*ptr).title);
    printf("Book author: %s\n", (*ptr).author);
    printf("Book author: %.2f\n", (*ptr).price);
    printf("Book data: %d/%d/%d\n", (*ptr).data.year, (*ptr).data.month, (*ptr).data.day);
    printf("Book Publisher: %s\n", (*ptr).publisher);
}
void Test5(void)
{
    struct Book1 book = {"FishC", "xsj", 48.8, {2023, 8, 16}, "chubanshe"};
    struct Book1 *ptr;
    ptr = &book;
    printf("Book title: %s\n", ptr->title);
    printf("Book author: %s\n", ptr->author);
    printf("Book author: %.2f\n", ptr->price);
    printf("Book data: %d/%d/%d\n", ptr->data.year, ptr->data.month, ptr->data.day);
    printf("Book Publisher: %s\n", ptr->publisher);
}
int main()
{
    // Test1();
    // Test2();
    // Test3();
    // Test4();
    Test5();

    return 0;
}