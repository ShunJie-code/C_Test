//操作结果：删除L的第i个数据元素，并用e返回其值，L的长度-1
Status ListDelete(SqList *L,int i,Elemtype *e)
{
    int K;
    if(L->length==0)//这句话很重要，在循环删除时
    {
        return ERROR;
    }
    if(i<1||i>L->length)
    {
        return ERROR;
    }
    *e=L->data[i-1];
    if(i<L->length)
    {
        for(k=i;k<L->length;k++)
        {
            L->data[k-1]=L->data[k];
        }
    }
    L->length--;
    return OK;
}