#include "kmp.h"
#include "stdio.h"

void GetNext(char *T, int *next)
{
    int j = 0;
    int i = 1;
    next[1] = 0;
    while (i < T[0])
    {
        if (0 == j || T[i] == T[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

void GetNextVal(char *T, int *nextval)
{
    int i = 1;
    int j = 0;
    nextval[1] = 0;
    while (i < T[0])
    {
        if (j == 0 || T[i] == T[j])
        {
            ++i;
            ++j;
            if (T[i] != T[j])
            {
                nextval[i] = j;
            }
            else
            {
                nextval[i] = nextval[j];
            }
        }
        else
            j = nextval[j];
    }
}
/**
 * 返回子串T在主串S中第pos个字符之后的位置
 * pos > 0
 */
int Index_KMP(char *s, char *t, int pos)
{
    int i = pos;
    int j = 1;
    int next[255];
    GetNext(t, next);
    while (i <= s[0] && j <= t[0])
    {
        if (j == 0 || s[i] == t[j])
        {
            i++;
            j++;
            // printf("%d, %d, %c, %c\n", i, j, s[i], t[i]);
        }
        else
        {
            j = next[j];
        }
    }
    if (j > t[0])
    {
        return i - t[0];
    }
    else 
        return 0;
}

/**
 * 返回子串T在主串S中第pos个字符之后的位置
 * 若不存在则返回0
 * 但该方法的next数组 效率更高，
 */
int Index_KMP_BETTER(char *s, char *t, int pos)
{
    int i = pos;
    int j = 1;
    int next[255];
    GetNextVal(t, next);
    // 当字符串S没有到顶且T也没有遍历完的时候，还需要继续搜索
    while (i <= s[0] && j <= t[0])
    {
        // i 会一直累加，而 j 按照 next 数组变化
        if (s[i] == t[j] || j == 0)
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j > t[0])
    {
        return i - t[0];
    }
    else
    {
        return 0;
    }
}