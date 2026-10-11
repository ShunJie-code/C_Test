#ifndef COMMON_9_H
#define COMMON_9_H

#define MAXSIZE 20
typedef struct
{
    int r[MAXSIZE + 1];
    int length;
} SqList;

/**
 * @brief 交换顺序表中两个元素的位置
 * 
 * @param L 
 * @param i 
 * @param j 
 */
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

/**
 * @brief 直接插入排序算法
 * 
 * @param L 
 */
void InsertSort(SqList *L);

/**
 * @brief  选择排序算法
 * 
 * @param L 
 */
void SelectSort(SqList *L);

/**
 * @brief 快速排序，冒泡的升级版本
 * 
 * @param sq 
 */
void QSort(SqList *sq);


#endif