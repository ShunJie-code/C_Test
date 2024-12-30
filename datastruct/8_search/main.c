/**
 * 第8章 查找算法
 * 70 顺序查找
 */
#include <stdio.h>
#include <stdlib.h>
#include "search.h"
#include <time.h>

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

struct Apple
{
    int i;
    double d[100000];
};

struct Apple *g_pa = NULL;
struct Apple g_a;

int Test4(void) 
{
    time_t current_time;
    struct timespec ts;
    // 获取当前时间的时间戳
    current_time = time(NULL);  // 秒级时间戳
    clock_gettime(CLOCK_REALTIME, &ts);  // ns级别时间戳
    
    // 打印时间戳
    printf("Seconds: %ld, Nanoseconds: %ld\n", ts.tv_sec, ts.tv_nsec);
    printf("Current timestamp: %ld\n", current_time);
    
    return 0;
}

/**
 * 测试时间区别，内存拷贝和指针赋值
 */
void Test2(void)
{
    struct Apple tmp = { 0 };
    tmp.i = 10;
    tmp.d[0] = 9.999;
    Test4();    // 48031674 ns
    g_pa = &tmp;
    Test4();    // 48047508 ns
    g_a = tmp;
    Test4();    // 48355109 ns
}

void Test3(void)
{ 
    printf("%s:\n", __func__);
    g_pa = malloc(sizeof(struct Apple));
    Test2();
    printf("%d, %f\n", g_pa->i, g_pa->d[0]);
    printf("%d, %f\n", g_a.i, g_a.d[0]);
}

int main(void)
{
    Test3();
    // Test1();
    return 0;
}