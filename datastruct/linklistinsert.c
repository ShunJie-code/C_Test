//操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
Status ListInsert(LinkList *L,int i,ElemType e)
{
    int j;
    LinkList p,s;
    p=*L;
    j=1;
    while(p && j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
    {return ERROR}
    s=(LinkList)malloc(sizeof(Node));//返回为指针，强制转换为Linklist类型指针
    s->data=e;
    //先插入指针后插入值
    s->next=p->next;
    p->next=s;
    return 0;
}