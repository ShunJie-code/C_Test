#ifndef COMMON_9_H
#define COMMON_9_H

#define MAXSIZE 10
typedef struct
{
    int r[MAXSIZE + 1];
    int length;
} SqList;

void swap(SqList *L, int i, int j);
/**
 * @brief 最简单排序实现
 * 
 * @param L 
 */
void EasyBubbleSort(SqList *L);
/**
 * @brief 正宗冒泡排序算法
 * 
 * @param L 
 */
void BubbleSort(SqList *L);
#endif