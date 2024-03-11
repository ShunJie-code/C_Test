/**
 * @file p46_2singleLinkedList.c
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
    char author[40];
    struct Book *next;
};

void GetInput(struct Book *book)
{
    printf("Please enter book's name:");
    scanf("%s", book->title);
    printf("Please enter book's author:");
    scanf("%s", book->author);
}

// 传入指针的指针
void AddBook(struct Book **library)
{
    struct Book *book;
    // struct Book *temp;
    static struct Book *tail;
    book = (struct Book *)malloc(sizeof(struct Book));
    if (book == NULL)
    {
        printf("Fail to malloc memmory!\n");
        exit(1);
    }

    GetInput(book);

    if (*library == NULL) {
        *library = book;
        // (*library)->next = NULL;
        book->next = NULL;
    }
    else {
        // 尾插法
        tail->next = book;
        book->next = NULL;
    }
    tail = book;
}

// 遍历链表
void PrintLibrary(struct Book *library)
{
    struct Book *book;
    int count = 1;
    book = library;
    while (book != NULL)
    {
        printf("Book %d:\n", count);
        printf("Book's title: %s\n", book->title);
        printf("Book's author: %s\n", book->author);
        book = book->next;
        count++;
    }
    
}

void ReleaseLibrary(struct Book **library)
{
    struct Book *temp;

    while (*library != NULL)
    {
        temp = (*library);
        (*library) = (*library)->next;
        free(temp);
    }
}
void Test1(void)
{
    struct Book *library = NULL;

    char ch;

    while (1)
    {
        printf("Do you want to enter book's infomation(Y/N): ");
        do
        {
            ch = (char)getchar();
        } while (ch != 'Y' && ch != 'N');
        
        if (ch == 'Y')
        {
            AddBook(&library);
        }
        else
        {
            break;
        }
    }
    
    printf("Do you want to print book's info(Y/N): ");
    
    do
    {
        ch = (char)getchar();
    } while (ch != 'Y' && ch != 'N');
    
    if (ch == 'Y')
    {
        PrintLibrary(library);
    }
    
    ReleaseLibrary(&library);
}

int main()
{
    Test1();
    return 0;
}