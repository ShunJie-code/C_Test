/**
 * @file queue4huffman.h
 * @author your name (you@domain.com)
 * @brief queue's define for huffman tree
 * @version 0.1
 * @date 2025-02-09
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef QUEUE4HUFFMAN_H
#define QUEUE4HUFFMAN_H

#include "common_6.h"

typedef BiTNode *HuffmanTNodePtr;

typedef struct HufQueueNode
{
    HuffmanTNodePtr val;
    unsigned int priority;   // 出现多少次
    struct HufQueueNode *next;
} HufQueueNode;

/**
 * @brief 根据出现的次数从低到高排列的队列
 * 
 */
typedef struct HufQueue
{
    unsigned int size;
    HufQueueNode *first;
} HufQueue;

/**
 * @brief 初始化huffman队列
 * 
 * @param q 
 */
void InitHufQueue(HufQueue **q);

/**
 * @brief 添加元素进入huffman队列
 * 
 * @param q 
 * @param val 
 * @param priority 
 */
void AddHufQueue(HufQueue **q, HuffmanTNodePtr val, unsigned int priority);

/**
 * @brief Get the Huffma Tree Node From Queue object
 * 
 * @param q 
 * @return HuffmanTNodePtr 
 */
HuffmanTNodePtr GetHufTNodeFromQueue(HufQueue **q);
#endif