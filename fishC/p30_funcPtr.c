/**
 * @file p30_funcPtr.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 指针函数 函数指针 
 * @version 0.1
 * @date 2023-11-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#define CASE 1
// 指针函数
// tips: 不要返回局部变量的指针
// const常量存储区的指针-static静态存储区的指针-动态存储区的指针均可以返回
char *GetWord(char c)
{
    // static char *str = "";   // 字符串会放在静态存储区
    char *str = "";             //字符串会放在常量存储区
    // char *sss = "123";       // 注释会影响只读区的大小
    switch (c)
    {
    case 'A':
        return "apple";         //字符串会放在常量存储区,注释会影响只读区的大小
    case 'B':
        str = "banana";
        break; //没有 break 则会往下执行
    case 'C':
        return "cat";
    default:
        return "none";
    }
    // *str = 'B'; // 常量不允许修改
    // str = "lalala"; // 不会影响只读区的大小
    return str;
}

void Test3(void)
{
    char input;
    printf("Please enter a char:");
    scanf("%c", &input);
    printf("%s\n", GetWord(input));
}

// 将函数指针作为参数传入
int Add(int num1, int num2)
{
    return num1 + num2;
}
int Sub(int num1, int num2)
{
    return num1 - num2;
}

int calc(int (*fp)(int, int), int num1, int num2)
{
    return (*fp)(num1, num2); //return fp(num1, num2);
}

void Test1(void)
{
    printf("3 + 5 = %d\n", calc(&Add, 3, 5)); // printf("3 + 5 = %d\n", calc(Add, 3, 5));
    printf("3 - 5 = %d\n", calc(&Sub, 3, 5)); // printf("3 - 5 = %d\n", calc(Sub, 3, 5));
}

// 函数指针作为返回值
#if CASE
// 写法一
typedef int (*Operation)(int, int);
Operation Select(char op)
{
    switch (op)
    {
    case '+':
        return Add;
    case '-':
        return Sub;
    default:
        return Add; // 没有这一句异常的话，程序直接退出
        break;
    }
}
#else
// 写法二
int (*Select(char op))(int , int)
{
    switch (op)
    {
    case '+':
        return Add;
        break;
    case '-':
        return Sub;
    default:
        return Add;
        break;
    }
}
#endif

void Test2(void)
{
    int num1;
    int num2;
    char op;
#if CASE
    Operation fp;
#else 
    int (*fp)(int, int);
#endif
    while (1)
    {
        printf("Please enter a equation(1+2): ");
        scanf("%d%c%d", &num1, &op, &num2);
        if (op == 'q') {
            break;
        }
        fp = Select(op);
        printf("%d %c %d = %d\n", num1, op, num2, calc(fp, num1, num2));
    }
}

int main(void)
{
    // Test1();
    // Test2();
    Test3();
    return 0;
}