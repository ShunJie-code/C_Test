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
    InitHufQueue(&huffmanQueue);
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
static void TraverseTree(HuffmanTree tree, HufTable **table, int k, char *code)
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
    if (tree->lchild != NULL)
    {
        code[k] = '0';
        TraverseTree(tree->lchild, table, k + 1, code);
    }
    if (tree->rchild != NULL)
    {
        code[k] = '1';
        TraverseTree(tree->rchild, table, k + 1, code);
    }
}

HufTable *HUF_BuildTable(HuffmanTree huffmanTree)
{
    HufTable *table = (HufTable *)malloc(sizeof(HufTable));
    table->first = NULL;
    table->last = NULL;
    char code[256];
    int k = 0;
    TraverseTree(huffmanTree, &table, k, code);
    return table;
}

void HUF_Encode(HufTable *table, char *str)
{
    HufTableNode *traversal;
    printf("Encoding\nInput string : %s\nEncode string : ", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        traversal = table->first;
        while (traversal->symbol != str[i])
        {
            traversal = traversal->next;
        }
        printf("%s", traversal->code);
    }
    putchar('\n');
}

void HUF_Decode(HuffmanTree tree, char *str)
{
    HuffmanTree root = tree;
    printf("Decoding:\nInput string : %s\nDecoded string : ", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (tree->lchild == NULL && tree->rchild == NULL)
        {
            printf("%c", tree->data);
            tree = root;
        }
        if (str[i] == '0')
            tree = tree->lchild;
        if (str[i] == '1')
            tree = tree->rchild;
        if (str[i] != '0' && str[i] != '1')
        {
            printf("The input string is not coded correctly!\n");
            return;
        }
    }
    // 打印最后一个字符
    if (tree->lchild == NULL && tree->rchild == NULL)
    {
        printf("%c", tree->data);
        tree = root;
    }
    putchar('\n');
}
