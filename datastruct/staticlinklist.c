//
Status InitList(StaticLinkList space)
{
    int i;
    for(i=0;i<MAXSIZE-1;i++){
        space[i].cur=i+1;//当前数据的游标等于下一个数据的下标
    }
    space[MAXSIZE-1].cur=0;
    return OK;
}

int Malloc_SLL(StaticLink space)//获取空闲分量的下标
{
    int i=space[0].cur;      //找出待插入位置
    if(space[0].cur)
    space[0].cur=space[i].cur;//第一个元素的游标指向下一个空闲分量的下标，备用
    return i;
}

Status ListInsert(StaticLinkList L,int i,ElemType e)//插入元素
{
    int j,k,l;
    k=MAX_SIZE-1;
    if(i<1||i>ListLength(L)+1)
    {
        return ERROR;
    }
    j=Malloc_SLL(L);
    if(j)
    {
        L(j).data=e;
        for(l=1;l<=i-1;l++)
        {
            k=L[k].cur;   
        } 
        L[j].cur=L[k].cur;
        L[k].cur=j;
            return OK;
    }
    return ERROR;
}

Status ListDelete(StaticLinkList L;int i)//删除元素
{
   int j,k;
   if(i<1||i>ListLength(L))
   {
       return ERROR;
   }
   k=MAX_SIZE-1;
   for(j=1;j<=i-1;j++)
   {
       k=L[k].cur;//前一个元素
   }
   j=L[k].cur;//找到要删的位置
   L[k].cur=L[j].cur;//前一个元素指向下一个元素
    Free_SLL(L,j);
    return OK;
}

void Free_SLL(StaticLinkList space,int k){//要将删除的位置加入备用链表
    space[k].cur=space[0].cur;
    space[0].cur=k;
}
/*返回L中数据元素个数*/
int ListLength(StaticLinkList L)
{
    int j=0;
    int i=L[MAXSIZE-1].cur;
    while(i)
    {
        i=L[i].cur;
        j++;
    }
    return j;
}