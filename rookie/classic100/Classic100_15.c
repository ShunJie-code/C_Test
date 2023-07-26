/**
 * @file Classic100_15.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 利用条件运算符分段表示学生的成绩
 * @version 0.1
 * @date 2023-05-14
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <stdio.h>

int main()
{
    int score;
    char grade;
    printf("please enter student's score:\n");
    scanf("%d", &score);
    grade = (score >= 90) ? 'A' : ((score >= 60) ? 'B' : 'C');
    printf("%c\n", grade);
    return 0;
}