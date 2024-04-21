#define MAXSIZE 10
typedef struct{
    int r[MAXSIZE+1];
    int length;
}SqList;
void swap(SqList *L,int i,int j){//形参为数组下标
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}