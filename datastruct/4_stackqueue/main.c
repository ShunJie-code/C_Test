/**
 * 24 栈的清除和释放
 * 25 使用栈进制转换
 * 26 栈的链式存储结构
 * 27 逆波兰计算器
 * 28 培养高级思维，中缀表达式转化为后缀表达式
 * 29 中缀表达式转化为后缀表达式
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "sequencestack.h"
#include "linkstack.h"
#include "linkqueue.h"

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

// 链栈的测试
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

// 逆波兰计算器，同时支持小数点
static Status ReversePolishCalculator(void)
{
#ifdef DOUBLE_TYPE
    SqStack s;
    ElemType e1, e2;
    ElemType e;
    int i;
    char c;
    char str[MAXSIZE];    // 缓冲区，接受输入的数字

    StackInit(&s);

    printf("请按逆波兰表达式输入待计算表达式，数据与运算符号用空格隔开:\n");
    scanf("%c", &c);
    while (c != '\n')
    {
        // 将表达式中的数字压入栈内
        while (isdigit(c) || c == '.')
        {
            str[i++] = c;
            str[i] = '\0';
            if (i >= MAXSIZE)
            {
                printf("输入数据过大，超出缓冲区\n");
                return ERROR;
            }
            scanf("%c", &c);
            if (c == ' ')
            {
                e = atof(str);
                StackPush(&s, e);
                i = 0;
                break;
            }
        }
        
        switch (c)
        {
        case '+':
            StackPop(&s, &e1);
            StackPop(&s, &e2);
            StackPush(&s, e1 + e2);
            break;
        case '-':
            StackPop(&s, &e1);
            StackPop(&s, &e2);
            StackPush(&s, e2 - e1);
            break;
        case '*':
            StackPop(&s, &e1);
            StackPop(&s, &e2);
            StackPush(&s, e2 * e1);
            break;
        case '/':
            StackPop(&s, &e1);
            StackPop(&s, &e2);
            if (e1 != 0)
            {
                StackPush(&s, e2 / e1);
            }
            else
            {
                printf("除数不能为0!\n");
                return ERROR;
            }
            break;
        default:
            break;
        }
        scanf("%c", &c);
    }
    StackPop(&s, &e);
    printf("计算结果为：%f\n", e);
#endif
    return SUCCESS;
}

// 中缀输入法转化为后缀输入法
static Status Infix2Suffix(void)
{
#ifdef CHAR_TYPE
    SqStack s;
    ElemType e;
    ElemType c;
    unsigned short flag;
    StackInit(&s);
    printf("请输入中缀表达式：\n");
    scanf("%c", &c);
    printf("对应的后缀表达式：\n");
    while (c != '\n')
    {
        flag = 1;
        while (c >= '0' && c <= '9')
        {
            putchar(c);
            scanf("%c", &c);
            if (c == '.' && flag == 1)
            {
                putchar(c);
                scanf("%c", &c);
                flag = 0;
            }
            if (c < '0' || c > '9')
            {
                putchar(' ');
            }
        }   
        
        if (')' == c)
        {
            StackPop(&s, &e);
            while (e != '(')
            {
                printf("%c ", e);
                StackPop(&s, &e);
            }
        }
        else if ('+' == c || '-' == c)
        {
            if (StackLen(s) == 0)
            {
                StackPush(&s, c);
            }
            else
            {
                do
                {
                    StackPop(&s, &e);
                    if ('(' == e)
                    {
                        StackPush(&s, e);
                    }
                    else
                    {
                        printf("%c ", e);
                    }
                } while (StackLen(s) && '(' != e);
                StackPush(&s, c);
            }
        }
        else if ('*' == c || '/' == c || '(' == c)
        {
            StackPush(&s, c);
        }
        else if ('\n' == c)
        {
            break;
        }
        else
        {
            printf("用户输入出错\n");
            return ERROR;
        }
        scanf("%c", &c);
    }
    while (StackLen(s) != 0)
    {
        StackPop(&s, &e);
        printf("%c ", e);
    }
    putchar('\n');
#endif
    return SUCCESS;
}

static void Test4(void)
{
    Status ret;
    ret = Infix2Suffix();
    if (ret != SUCCESS)
    {
        printf("中缀表达式转化为后缀表达式失败\n");
        return;
    }
    ret = ReversePolishCalculator();
    if (ret != SUCCESS)
    {
        printf("逆波兰计算器计算失败\n");
        return;
    }
}

// 测试链队列
static void Test5(void)
{
    LinkQueue q;
    LQInit(&q);
    ElemType e;
    int queueLen;

    printf("%s_%d: \n", __func__, __LINE__);
    // 测试入队列
    for (int i = 0; i < 30; i++)
    {
        LQEnter(&q, i);
    }
    // 测试读取队列的长度
    queueLen = LQGetLen(q);
    printf("%d: Queue length is %d\n", __LINE__, queueLen);
    // 测试出队列
    for (int j = 0; j < 39; j++)
    {
        if (LQOut(&q, &e) == SUCCESS)
            printf("%d ", e);
        else
            break;
    }
    putchar('\n');
    // 全部出栈后，栈长度为0
    queueLen = LQGetLen(q);
    printf("%d: Queue length is %d\n", __LINE__, queueLen);
    LQDestroy(&q);
    if (q.front == NULL && q.rear == NULL)
    {
        printf("LQDestroy is finished!\n");
    }
    queueLen = LQGetLen(q);
    printf("%d: Queue length is %d\n", __LINE__, queueLen);
}



int main(void)
{
    // Test1();
    // Test2();
    // Test3();
    // Test4();
    Test5();
    return 0;
}