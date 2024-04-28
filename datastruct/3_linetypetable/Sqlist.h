/**
 * 线性表顺序存储结构头文件
*/
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;               // 线性表当前的长度
}SqList;

void ShowListData(SqList l);
int LocateElem(SqList l, int e);

Status InitList(SqList *l, int *arr, int len);
Status GetElem(SqList l, int i, ElemType *e);
Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *l, int i, ElemType *e);
void UnionL(SqList *La, SqList Lb);


