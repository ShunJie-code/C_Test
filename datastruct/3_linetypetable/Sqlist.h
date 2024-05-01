/**
 * 线性表顺序存储结构头文件
*/
#include "common.h"

typedef struct
{
    ElemType data[MAXSIZE];
    int length;               // 线性表当前的长度
}SqList;

void ShowListData(SqList l);
int LocateElem(SqList l, int e);

Status GetElem(SqList l, int i, ElemType *e);

Status InitList(SqList *l, int *arr, int len);
Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *l, int i, ElemType *e);

void UnionL(SqList *La, SqList Lb);


