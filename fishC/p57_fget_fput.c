/**
 * @file p57_fget_fput.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 读写文件
 * @version 0.1
 * @date 2023-07-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void Test1(void)
{
    FILE *fp1;
    FILE *fp2;
    int ch; // 类型为int 实际是字符
    fp1 = fopen("hello.txt", "r");
    if (fp1 == NULL) {
        printf("%s:fopen fail!\n", __LINE__);
        exit(EXIT_FAILURE);
    }
    fp2 = fopen("fishC.txt", "w");// w模式会创建新文件夹
    if (fp2 == NULL) {
        printf("%s:fopen fail!\n", __LINE__);
        exit(EXIT_FAILURE);
    }
    ch = fgetc(fp1);
    while (ch != EOF) {
        fputc(ch, fp2);
        ch = fgetc(fp1);
    } 

    fclose(fp1);
    fclose(fp2);
}

void Test2(void)
{
    FILE *fp;
    char buffer[MAX];
    fp = fopen("lines.txt", "w");
    if (fp == NULL) {
        printf("%s:fopen fail!\n", __LINE__);
        exit(EXIT_FAILURE);
    }
    fputs("Line 1\n", fp);
    fputs("Line 2\n", fp);
    fputs("Line 3\n", fp);

    fclose(fp); // 类似于保存

    fp = fopen("lines.txt", "r");
    if (fp == NULL) {
        printf("%s:fopen fail!\n", __LINE__);
        exit(EXIT_FAILURE);
    }

    while (!feof(fp)) {
        fgets(buffer, MAX, fp);
        // 当fp = eof 时, buffer不变
        printf("%s", buffer);
    }

}

int main()
{
    Test1();
    Test2();
    return 0;
}
