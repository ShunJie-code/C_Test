//指针数组
typedef struct Node
{
    ElemType data;//数据域指针域
    struct Node* Next;//
}Node;
typedef struct Node* LinkList;
//链表元素提取
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList p;
    p=L->next;//用p来记录链表的第一个地址
    j=1;

    while(p && j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
    {
        return ERROR;

    }
    *e=p->data;
    return OK;
}