
// 二叉树的二叉链表结构定义
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 查找操作-递归查找二叉排序树T中是否存在key
// 指针f指向T的双亲，初始调用值为null
// 若查找成功，则指针p指向该数据元素结点，并返回true
// 否则p指向查找路径上访问的最后一个结点并返回false

Status SearchBSF(BiTree T, int key, BiTree f, BiTree *p)
{
    if (!T)
    {
        *p = f;
        return FALSE;
    }
    else if (key == T->data)
    {
        *p = T;
        return TRUE;
    }
    else if (key < T->data)
        return SearchBSF(T->lchild, key, T, p); // 这里输入的变量P就是函数的指针变量
    else
        return SearchBSF(T->rchild, key, T, p); //
}

// 插入操作-当二叉排序树中不存在关键字为key的数据元素时，插入key返回true，否则返回false
Status InseartBSF(BiTree *T, int key)
{
    BiTree p, s;
    if (!SearchBSF(*T, key, NULL, &p))
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if (!p)
            *T = s;
        else if (key < p->data)
            p->lchild = s;
        else
            p->rchild = s;
        return TRUE;
    }
    return FALSE;
}
