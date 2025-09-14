// 程序需要使用符合 POSIX.1b (1993 年 9 月修订版) 标准的功能
// 解决c/c++工具提示宏定义错误
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <time.h>
void CheckSearchResult(int index, int key)
{
    if (index != 0)
        printf("Element %d index is %d\n", key, index);
    else
        printf("Element %d is not found\n", key);
}

void ShowTimeStamp(void) 
{
    time_t current_time;
    current_time = time(NULL);  // 秒级时间戳
    printf("Current timestamp: %ld\n", current_time);
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);  // ns级别时间戳
    printf("Seconds: %ld, Nanoseconds: %ld\n", ts.tv_sec, ts.tv_nsec);
}