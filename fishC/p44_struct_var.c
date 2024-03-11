/**
 * @file p44_struct_var.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 传递结构体变量到函数不如传递指针的开销小
 * @version 0.1
 * @date 2023-08-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct Date
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
    struct Date date;
    char publisher[40];
};

struct Book GetInputBook(struct Book book)
{
    printf("Please enter a title:\n");
    scanf("%s", book.title);
    printf("Please enter the author:\n");
    scanf("%s", book.author);
    printf("Please enter the price:\n");
    scanf("%f", &book.price);
    printf("Please enter the date(year/month/day):\n");
    scanf("%d", &book.date.year);
    scanf("%d", &book.date.month);
    scanf("%d", &book.date.day);
    printf("Please enter the publisher:\n");
    scanf("%s", book.publisher);
    return book;
}
void DumpBookInfo(struct Book book)
{
    printf("Book's title is %s\n", book.title);
    printf("Book's author is %s\n", book.author);
    printf("Book's price is %.2f\n", book.price);
    printf("Book's date is %d/%d/%d\n", book.date.year, book.date.month, book.date.day);
    printf("Book's publisher is %s\n", book.publisher);
}
// 录入书籍的信息
void Test1(void)
{
    struct Book b1, b2;
    printf("Please enter first book info...\n");
    b1 = GetInputBook(b1);

    printf("\nPlease enter second book info...\n");
    b2 = GetInputBook(b2);

    printf("\nFirst book info:\n");
    DumpBookInfo(b1);
    printf("\nSecond book info:\n");
    DumpBookInfo(b2);
}

// 作为开发者要考虑到传递结构体变量，对程序的开销很大
void GetInputPBook(struct Book *book)
{
    printf("Please enter a title:\n");
    scanf("%s", book->title);
    printf("Please enter the author:\n");
    scanf("%s", book->author);
    printf("Please enter the price:\n");
    scanf("%f", &book->price);
    printf("Please enter the date(year/month/day):\n");
    scanf("%d", &book->date.year);
    scanf("%d", &book->date.month);
    scanf("%d", &book->date.day);
    printf("Please enter the publisher:\n");
    scanf("%s", book->publisher);
}
void DumpPBookInfo(struct Book *book)
{
    printf("Book's title is %s\n", book->title);
    printf("Book's author is %s\n", book->author);
    printf("Book's price is %.2f\n", book->price);
    printf("Book's date is %d/%d/%d\n", book->date.year, book->date.month, book->date.day);
    printf("Book's publisher is %s\n", book->publisher);
}
void Test2(void)
{
    struct Book b1, b2;
    printf("Please enter first book info...\n");
    GetInputPBook(&b1);

    printf("\nPlease enter second book info...\n");
    GetInputPBook(&b2);

    printf("\nFirst book info:\n");
    DumpPBookInfo(&b1);
    printf("\nSecond book info:\n");
    DumpPBookInfo(&b2);
}

// 动态申请结构体空间
void Test3(void)
{
    struct Book *b1, *b2;
    b1 = (struct Book *)malloc(sizeof(struct Book));
    b2 = (struct Book *)malloc(sizeof(struct Book));
    if (b1 == NULL || b2 == NULL)
    {
        printf("malloc fail\n");
        exit(1);
    }

    printf("Please enter first book info...\n");
    GetInputPBook(b1);
    printf("\nPlease enter second book info...\n");
    GetInputPBook(b2);

    printf("\n The first book info...\n");
    DumpPBookInfo(b1);
    printf("\n The Second book info...\n");
    DumpPBookInfo(b2);

    free(b1);
    free(b2);
}


int main(void)
{
    // Test1();
    // Test2();
    Test3();

    return 0;
}