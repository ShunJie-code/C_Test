/**
 * IO 缓冲区
 * 按块换成
 * 按行缓存
 * 不缓存
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void Test1(void)
{
    FILE *fp;
    fp = fopen("output.txt", "w");
    if (fp == NULL)
    {
        perror("Open file failed, reason is ");
        exit(EXIT_FAILURE);
    }
    fputs("I love hui_a_hui!\n", fp);
    getchar();  // 数据存在缓冲区，并没有写入
    fclose(fp); // 数据写入
}

/**
 * 输出流
*/
static void Test2(void)
{
    char buff[1024];
    memset(buff, '\0', sizeof(buff));
    // _IONBF没有缓冲区
    // setvbuf(stdout, buff, _IONBF, 1024);
    // _IOFBF满缓冲区
    setvbuf(stdout, buff, _IOFBF, 1024);
    fprintf(stdout, "Welcome to C world!\n");
    // fflush可以打破块缓冲区，直接输出，不必等待
    fflush(stdout);
    fprintf(stdout, "Show the message until enter a char!\n");
    getchar();
}

int main(void)
{
    Test2();
    // printf("hello world, xsj\n");
    return 0;
}