#include <stdio.h>
#include <stdlib.h>
#include "queue4huffman.h"
#define MAX_SZ 256

void InitHufQueue(HufQueue **q)
{
    (*q) = (HufQueue *)malloc(sizeof(HufQueue));
    if (NULL == (*q))
    {
        perror("HufQueue malloc fail!");
        return;
    }
    (*q)->first = NULL;
    (*q)->size = 0;
    return;
}

void AddHufQueue(HufQueue **q, HuffmanTNodePtr val, unsigned int priority)
{
    if ((*q)->size == MAX_SZ)
    {
        printf("HufQueue is full\n");
        return;
    }
    HufQueueNode *pQNode = (HufQueueNode *)malloc(sizeof(HufQueueNode));
    if (NULL == pQNode)
    {
        perror("HufQueueNode malloc fail!");
        return;
    }
    pQNode->priority = priority;
    pQNode->val = val;
    if ((*q)->size == 0 || (*q)->first == NULL)
    {
        pQNode->next = NULL;
        (*q)->first = pQNode;
        (*q)->size = 1;
        return;
    }
    else
    {
        // 根据优先级排序
        if (priority <= (*q)->first->priority)
        {
            pQNode->next = (*q)->first;
            (*q)->first = pQNode;
            (*q)->size++;
            return;
        }
        else
        {
            HufQueueNode *iterator = (*q)->first;
            while (iterator->next != NULL)
            {
                if (priority <= iterator->next->priority)
                {
                    pQNode->next = iterator->next;
                    iterator->next = pQNode;
                    (*q)->size++;
                    return;
                }
                iterator = iterator->next;
            }
            if (iterator->next == NULL)
            {
                pQNode->next = NULL;
                iterator->next = pQNode;
                (*q)->size++;
                return;
            }
        }
    }
}

HuffmanTNodePtr GetHufTNodeFromQueue(HufQueue **q)
{
    HuffmanTNodePtr pTNode = NULL;
    HufQueueNode *tmp;

    if ((*q)->size > 0)
    {
        tmp = (*q)->first;
        pTNode = tmp->val;
        (*q)->first = tmp->next;
        (*q)->size--;
        free(tmp);
    }
    else
    {
        printf("HufQuue is empty\n");
    }
    return pTNode;
}
