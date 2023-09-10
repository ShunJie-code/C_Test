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

void insertNode(struct Node **head, int value)
{
    struct Node *previous;
    struct Node *current;
    struct Node *new;
        
}
int main(void)
{
    struct Node *head = NULL;
    int input;

    while (1)
    {
        printf("Please enter a int (-1 means exit) :");
        scanf("%d", &input);
        if (input == -1) {
            break;
        }
        insertNode();
    }
    
}
