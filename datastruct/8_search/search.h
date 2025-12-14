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
#ifndef SEARCH_H
#define SEARCH_H
/**
 * @brief 顺序表查找
 * 
 * @param a 数组指针 a[0] 不存值
 * @param n 数组长度
 * @param key 待搜索的值
 * @return int 搜到的值的位置，没有则返回0
 */
int SqSearch(int *a, int n, int key);

/**
 * @brief 哨兵顺序查找
 * 
 * @param a a[0] 不存值
 * @param n 
 * @param key 
 * @return int 搜到的值的位置，没有则返回0
 */
int SqSentinelSearch(int *a, int n, int key);

/**
 * @brief 二分查找，适用于排序后的数组
 * 
 * @param a 数组指针 a[0] 不存值
 * @param n 数组长度
 * @param key 待搜索的值
 * @return int 搜到的值的位置，没有则返回0
 */
int BinarySearch(int *a, int n, int key);

#endif