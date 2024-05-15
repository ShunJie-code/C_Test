#include "common.h"

#define MAXSIZE 1000
typedef struct
{
    ElemType data;
    int cur;         // 游标
}Component, StaticLinkList[MAXSIZE];
