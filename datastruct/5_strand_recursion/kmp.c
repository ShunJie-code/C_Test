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

/**
 * 返回子串T在主串S中第pos个字符之后的位置
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