/**
 * @file p41_inlineFunc.c
 * @author XiaoShunJie (xiaoshunjie@qq.com)
 * @brief 内联函数及高级宏定义
 * @version 0.1
 * @date 2023-08-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>

#define SQUARE(x) ((x) * (x))

static void Test1(void)
{
    int i = 1;

    while (i <= 100) {
        // 从右向左开始计算
        printf("%d square is %d\n", i - 1, SQUARE(i++));
    }
}
void Test2(void)
{
    int i = 5;
    printf("%d\n", SQUARE(i++));// 30 linux下是25
}
// 内联函数
static inline int Square(int x)
{
    return x * x;
}
// 当可变参数的个数为0时,这里的##可以把把前面多余的","去掉,否则会编译出错。
#define DEBUGPRINT(format, ...) do{if (g_flag % 20 == 0) {printf(format, ##__VA_ARGS__);}}while(0)
int g_flag;
void Test3(void)
{
    int localVar = 1;
    g_flag = 1;
    while (g_flag <= 100)
    {
        // printf("%d square is %d\n", i - 1, Square(i++));
        DEBUGPRINT("%d square is %d\n", g_flag, Square(g_flag));// undefined reference to 'Square'
        DEBUGPRINT("%d localVal is %d\n", g_flag, localVar);
        localVar++;
        g_flag++;
    }
    
}
// 运算符 # 可以将变量转化为字符串
#define STR(s) # s
void Test4()
{
    // 实参的传入，多个空格会变成一个字符双引号会自动加上反斜杠
    printf(STR(Hello     %s num = %d\n), STR(fishC), 520);
}
// 运算符 ## 记号连接运算符
#define TOGETHER(x, y) x ## y
void Test5(void)
{
    printf("%d\n", TOGETHER(5, 20));
}

// 带参数的宏定义，也可以使用可变参数宏
#define SHOWLIST(...) printf(#__VA_ARGS__)
#define PRINT(format, ...) printf(#format, ##__VA_ARGS__)
void Test6(void)
{
    SHOWLIST(FishC, hello 520, 3.14\n);
    PRINT(Daying %s %d %lf \n, "FishC", 520, 3.14);
    PRINT(Empty string.\n);
}

int main()
{
    // Test1(); // 宏定义处理i++复合语句有问题
    // Test2();
    Test3();
    // Test4();
    // Test5();
    Test6();
    return 0;
}