#include <pthread.h>
#include <sched.h>
#include <stdio.h>

void *thread_function(void *arg)
{
    // 获取当前线程的调度参数
    struct sched_param param;
    int policy;
    unsigned long long count;
    pthread_getschedparam(pthread_self(), &policy, &param);

    while (1)
    {
        // 打印当前线程的优先级
        if (count % 900000000 == 0)
            printf("%s, Current thread priority: %d, policy = %d\n", __func__, param.sched_priority, policy);
        count++;
    }

    return NULL;
}

int main()
{
    int ret;

    pthread_t thread;
    pthread_attr_t attr;
    struct sched_param sched_param;

    // 初始化线程属性
    pthread_attr_init(&attr);

    // 设置线程为可以被抢占的
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);

    // 设置线程的调度策略为FIFO
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);

    // 设置线程的优先级
    sched_param.sched_priority = 99; // 设置为最高优先级
    ret = pthread_attr_setschedparam(&attr, &sched_param);
    if (ret != 0)
    {
        perror("pthread_attr_setschedparam");
        return -1;
    }

    // 创建线程
    ret = pthread_create(&thread, &attr, &thread_function, NULL);
    if (ret != 0)
    {
        perror("pthread_create");
        printf("xsj ret = %d\n", ret); // 权限不够就返回1
        return -1;
    }

    // 等待线程结束
    pthread_join(thread, NULL);

    // 清理线程属性
    pthread_attr_destroy(&attr);

    return 0;
}