#include <stdio.h>

// 局部的静态变量可以同名
void Test1(void)
{
    static int a = 0;
    a++;
    printf("%s: %d\n", __FUNCTION__, a);
}
void Test2(void)
{
    static int a = 20;
    a++;
    printf("%s: %d\n", __FUNCTION__, a);
}

int main(void)
{
    Test1();
    Test1();
    Test2();
    Test2();
    return 0;
}
