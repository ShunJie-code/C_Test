#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"
#include "queue4huffman.h"

HuffmanTree HUF_BuildTree(char *str)
{
    // 1 初始化数组
    int *probability = (int *)malloc(sizeof(int) * 256);
    for (int i = 0; i < 256; i++)
    {
        probability[i] = 0;
    }
    // 2 统计字符出现次数
    for (int i = 0; str[i] != '\0'; i++)
    {
        probability[(unsigned char)str[i]]++;
    }
    // 3 队列初始化
    HufQueue *huffmanQueue;
    InitQueue(&huffmanQueue);
    // 4 填充huffman队列
    for (int i = 0; i < 256; i++)
    {
        if (probability[i] != 0)
        {
            HuffmanTNode *pNode = (HuffmanTNode *)malloc(sizeof(HuffmanTNode));
            pNode->lchild = NULL;
            pNode->rchild = NULL;
            pNode->data = (char)i;
            AddHufQueue(&huffmanQueue, pNode, probability[i]);
        }
    }
    // 5 释放数组
    free(probability);

    // 6 构建huffman树
    int priority;
    HuffmanTNode *treeNode;
    HuffmanTNode *left;
    HuffmanTNode *right;
    while (huffmanQueue->size != 1) // size == 1 根节点
    {
        priority = huffmanQueue->first->priority;
        priority += huffmanQueue->first->next->priority;
        left = GetHufTNodeFromQueue(&huffmanQueue);
        right = GetHufTNodeFromQueue(&huffmanQueue);
        treeNode = (HuffmanTNode *)malloc(sizeof(HuffmanTNode));
        treeNode->lchild = left;
        treeNode->rchild = right;
        AddHufQueue(&huffmanQueue, treeNode, priority);
    }
    HuffmanTree tree = GetHufTNodeFromQueue(&huffmanQueue);
    return tree;
}

// 递归函数
static void TraverseTree(HuffmanTree tree, HuffmanTable **table, int k, char *code)
{
    if (tree->lchild == NULL && tree->rchild == NULL)
    {
        code[k] = '\0';

        HufTableNode *pNode = (HufTableNode *)malloc(sizeof(HufTableNode));
        if (pNode == NULL)
        {
            perror("HufTableNode malloc fail in TraverseTree");
            return;
        }
        
        // 申请内存，然后向内存内赋值
        pNode->code = (char *)malloc(sizeof(char) * (strlen(code) + 1));
        if (pNode->code == NULL)
        {
            perror("char malloc fail in TraverseTree");
            return;
        }
        strcpy(pNode->code, code);
        pNode->symbol = tree->data;
        pNode->next = NULL;
        if ((*table)->first == NULL)
        {
            (*table)->first = pNode;
            (*table)->last = pNode;
        }
        else
        {
            (*table)->last->next = pNode;
            (*table)->last = pNode;
        }
    }

    
}

HuffmanTable *HUF_BuildTable(HuffmanTree huffmanTree)
{
    HuffmanTable *table = (HuffmanTable *)malloc(sizeof(HuffmanTable));
    table->first = NULL;
    table->last = NULL;
    char code[256];
    int k = 0;
    TraverseTree(huffmanTree, &table, k, code);
    return table;
}
