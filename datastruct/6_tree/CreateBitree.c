// 按前序输入二叉树中结点的值
// #表示空树
void CreateBitree(BiTree *T)
{
    TElemType ch;
    scanf("%c", &ch);
    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T)
            exit(OVERFLOW);
        (*T)->data = ch;
        CreatrBiTree(&(*T)->lchild);
        CreatrBiTree(&(*T)->rchild);
    }
}