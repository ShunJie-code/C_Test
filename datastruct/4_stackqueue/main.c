/**
 * 24 栈的清除和释放
 * 25 使用栈进制转换
 * 26 栈的链式存储结构
 */
#include <stdio.h>
#include <math.h>
#include "stackapi.h"
#include "linkstack.h"

static void Test1(void)
{
#ifdef INT_TYPE
    SqStack sta;
    ElemType e;
    int staLen;

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
        else
        {
            break;
        }
    }
    putchar('\n');
    // 全部出栈后，栈长度为0
    staLen = StackLen(sta);
    printf("%d: Stack length is %d\n", __LINE__, staLen);
    StackDestroy(&sta);
    if (sta.base == NULL &&
        sta.top == NULL &&
        sta.stackSize == 0)
    {
        printf("StackDestroy is finished!\n");
    }
#endif
}

// 利用栈的数据结构的特点，将二进制数转换为十进制数
static void Test2(void)
{
#ifdef CHAR_TYPE
    ElemType c;
    SqStack s;
    int len;
    int sum = 0;

    StackInit(&s);
    printf("请输入二进制数，输入为回车表示结束：\n");
    
    scanf("%c", &c);
    while (c != '\n')        
    {
        StackPush(&s, c);
        scanf("%c", &c);
    }

    len = StackLen(s);
    printf("栈的当前容量是%d\n", len);
    for (int i = 0; i < len; i++)
    {
        StackPop(&s, &c);
        sum = sum + (c - '0') * pow(2, i);
    }
    printf("对应的十进制数是%d\n", sum);
#endif
}

// 逆波兰计算器
static void Test3()
{
#ifdef INT_TYPE
    LinkStack ls;
    ElemType e;
    int lsLen;
    ls.count = 0;
    
    printf("%s_%d: \n", __func__, __LINE__);

    for (int i = 0; i < 30; i++)
    {
        LsPush(&ls, i);
    }
   
    lsLen = ls.count;
    printf("%d: Stack length is %d\n", __LINE__, lsLen);
    // 测试出栈
    for (int j = 0; j < 39; j++)
    {
        if (LsPop(&ls, &e) == SUCCESS)
        {
            printf("%d ", e);
        }
        else
        {
            break;
        }
    }
    putchar('\n');
    // 全部出栈后，栈长度为0
    lsLen = ls.count;
    printf("%d: Stack length is %d\n", __LINE__, lsLen);
#endif
}

int main(void)
{
    // Test1();
    // Test2();
    Test3();
    return 0;
}