/**
 * @file search.h
 * @author your name (you@domain.com)
 * @brief 搜索算法的头文件
 * @version 0.1
 * @date 2025-04-02
 * 
 * @copyright Copyright (c) 2025
 * 
 */

void CheckSearchResult(int index, int key);


/**
 * @brief 顺序表查找
 * 
 * @param a 数组指针 a[0] 不存值
 * @param n 数组长度
 * @param key 待搜索的值
 * @return int 搜到的值的位置，没有则返回0
 */
int SQ_Search(int *a, int n, int key);

/**
 * @brief 哨兵顺序查找
 * 
 * @param a a[0] 不存值
 * @param n 
 * @param key 
 * @return int 搜到的值的位置，没有则返回0
 */
int SQ_SearchBetter(int *a, int n, int key);
