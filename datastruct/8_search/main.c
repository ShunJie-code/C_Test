/**
 * 第8章 查找算法
 * 70 顺序查找
 */
#include <stdio.h>
#include <time.h>
#include "search.h"

void Test1(void)
{
    int key = 8;
    int a[5] = {1, 2, 3, 4, 5};

    int index = SQ_Search(a, 5, key);
    if (index != 0)
        printf("Element %d index is %d\n", key, index);
    else
        printf("Element %d is not found\n", key);
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