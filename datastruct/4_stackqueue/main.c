#include <stdio.h>
#include "stackdefine.h"

void Test1(void)
{
    SqStack sta;
    int e;

    printf("%s_%d: \n", __func__, __LINE__);
    StackInit(&sta);
    // 测试压栈
    for (int i = 0; i < 30; i++)
    {
        StackPush(&sta, i);
    }
    // 测试出栈
    for (int j = 0; j < 39; j++)
    {
        if (StackPop(&sta, &e) == SUCCESS)
        {
            printf("%d ", e);
        }
        else {
            break;
        }
    }
    putchar('\n');
    
}

int main(void)
{
    Test1();
    return 0;
}