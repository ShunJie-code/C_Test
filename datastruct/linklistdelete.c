//操作结果：删除L中第i个位置的数据元素，返回删除的e，L的长度加减1
Status ListInsert(LinkList *L,int i,ElemType *e)
{
    int j;
    LinkList p,q;
    p=*L;
    j=1;
    while(p && j<i)
    {
        p=p->next;
        ++j;
    }

    if(!p||j>i)
    {return ERROR}

    q=p->next;
    p->next=q->next;

    *e=q->data;
    free(q);
    return OK;
}

Status GetMidNode(LinkList L,Elemtype *e)
{
    LinkList search,mid;
    mid=search=L;
    while(search->next!=NULL)
    {
        if(search->next->next!=NULL)//若能够移动两步，则动两步，否则一步
        {
            search=search->next->next;
            mid=mid->next;
        }
        else
        {
            search=search->next;
        }
    }
}