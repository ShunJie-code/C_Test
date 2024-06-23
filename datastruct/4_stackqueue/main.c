#include <stdio.h>
#include "stackapi.h"

void Test1(void)
{
    SqStack sta;
    int staLen;
    int e;

    printf("%s_%d: \n", __func__, __LINE__);
    StackInit(&sta);
    // 测试压栈
    for (int i = 0; i < 30; i++)
    {
        StackPush(&sta, i);
    }
    // 测试读取栈的长度
    staLen = StackLen(sta);
    printf("%d: Stack length is %d\n", __LINE__, staLen);
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
    // 全部出栈后，栈长度为0
    staLen = StackLen(sta);
    printf("%d: Stack length is %d\n", __LINE__, staLen);
}

int main(void)
{
    Test1();
    return 0;
}