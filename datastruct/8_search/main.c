/**
 * 第8章 查找算法
 * 70 顺序查找
 */
#include <stdio.h>

#include "search.h"
#include <linux/time.h>
// #include <time.h>

void Test1(void)
{
    int a[] = {0, 1, 2, 3, 4, 5};
    int key = 8;
    
    int index = SqSearch(a, sizeof(a) / sizeof(int) - 1, key);
    CheckSearchResult(index, key);

    key = 3;
    index = SqSearchBetter(a, sizeof(a) / sizeof(int) - 1, key);
    CheckSearchResult(index, key);

    index = BinarySearch(a, sizeof(a) / sizeof(int) - 1, key);
    CheckSearchResult(index, key);
}

int Test4(void) 
{
    // time_t current_time;
    // current_time = time(NULL);  // 秒级时间戳
    // printf("Current timestamp: %ld\n", current_time);
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);  // ns级别时间戳
    printf("Seconds: %ld, Nanoseconds: %ld\n", ts.tv_sec, ts.tv_nsec);
    return 0;
}

int main(void)
{
    Test4();
    Test1();
    Test4();
    return 0;
}