#define MAXSIZE 10
typedef struct{
    int r[MAXSIZE+1];
    int length;
}SqList;
void swap(SqList *L,int i,int j){
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}
//最简单排序实现
void BubbleSort0(SqList *L){
    int i,j;
    for(i=1;i<L->length;i++){
        for(j=i+1;j<=L->length;j++){
            if(L->r[i]>L->r[j]){
                swap(L,i,j);
            }
        }
    }
}
//正宗冒泡排序算法
void BubbleSort(SqList *L){
    int i,j;
    for(i=1;i<L->length;i++){       //这里只要循环到length前一位就好，因为最后一位必然最大
        for(j=L->length-1;j>=i;j--){//注意j是从后往前循环
            if(L->r[j]>L->r[j+1])   //前者大于后者，则交换
            swap(L ,j,j+1);
        }
    }
}