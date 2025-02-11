/**
 * huffman tree WPL最小
 * huffman 编码，左0右1
 * 定长编码，ACSII
 * 变长编码，根据字符出现次数规定
 * 前缀编码，没有任何编码是其他编码的前缀
 * 算法：
 * 1 build a priority queue
 * 2 build a huffman tree
 * 3 build a huffman table
 * 4 encode
 * 5 decode
 */
#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "common_6.h"

typedef BiTNode HuffmanTNode;
typedef BiTree HuffmanTree;

typedef struct HufTableNode
{
    char symbol;                // 字符
    char *code;                 // huffman编码
    struct HufTableNode *next;
} HufTableNode;

typedef struct HufTable
{
    HufTableNode *first;
    HufTableNode *last;
}HufTable;

/**
 * @brief 建立赫夫曼树
 * 
 * @param str 
 * @return BiTree 
 */
HuffmanTree HUF_BuildTree(char *str);

/**
 * @brief 建立赫夫曼编码表
 * 
 * @param huffmanTree 
 * @return HufTable 
 */
HufTable *HUF_BuildTable(HuffmanTree huffmanTree);

/**
 * @brief 根据编码表，进行赫夫曼编码
 * 
 * @param table 
 * @param str 格式如 "hello world"
 */
void HUF_Encode(HufTable *table, char *str);

/**
 * @brief 根据赫夫曼树，进行赫夫曼解码s
 * 
 * @param tree 
 * @param str 格式如 "0010010010101"
 */
void HUF_Decode(HuffmanTree tree, char *str);
#endif