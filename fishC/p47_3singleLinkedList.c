/**
 * @file p47_3singleLinkedList.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 单链表的插入
 * @version 0.1
 * @date 2023-09-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

// 插入节点
void InsertNode(struct Node **head, int value)
{
    struct Node *previous;
    struct Node *current;
    struct Node *new;
    current = *head;
    previous = NULL;
    while (current != NULL && current->value < value)
    {
        previous = current;
        current = current->next;
    }
    new = (struct Node *)malloc(sizeof(struct Node));
    if (new == NULL)
    {
        printf("Malloc failed.\n");
        exit(1);
    }
    new->value = value;
    new->next = current;
    if (previous == NULL)
    {
        *head = new;
    }
    else
    {
        previous->next = new;
    }    
}

void DeleteNode(struct Node **head, int value)
{
    struct Node *previous;
    struct Node *current;

    current = *head;
    previous = NULL;
    while (current != NULL && current->value != value)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Can't find matching nodes\n");
        return;
    }
    else
    {
        if (previous == NULL)
        {
            *head = current->next;
        }
        else
        {
            previous->next = current->next;
        }
        free(current);
    }
}

void PrintNode(struct Node *head)
{
    struct Node *current;
    current = head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    putchar('\n');
}

int main(void)
{
    struct Node *head = NULL;

    int input;
    printf("Test for inserting node...\n");
    while (1)
    {
        printf("Please enter a int (-1 means exit) :");
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        InsertNode(&head, input);
        PrintNode(head);
    }
    printf("Test for deleting node...\n");
    while (1)
    {
        printf("Please enter a int (-1 means exit) :");
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        DeleteNode(&head, input);
        PrintNode(head);
    }
    return 0;
}
