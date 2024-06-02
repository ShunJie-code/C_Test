/**
 * p17 循环链表
 */
#include <stdio.h>
#include <stdlib.h>

/*链表存储结构的定义*/
typedef struct CLinkList
{
    int data;
    struct CLinkList *next;
} node;

/************************************************************************/
/* 操作 */

/*初始化循环链表*/
void ds_init(node **pNode)
{
    int item;
    node *temp;
    node *target;

    printf("请输入结点的值，输入0完成初始化：\n");

    while (1)
    {
        scanf("%d", &item);
        /*在获取关键输入之前清除残留输入：在某些情况下，你可能希望在获取一个关键输入之前清除之前可能遗留的不相关输入。
        但请注意，这种用法可能并不总是可靠的，因为fflush(stdin)的行为在不同的系统和编译器中可能不一致。*/
        // fflush(stdin);

        if (item == 0)
            return;

        if (*pNode == NULL)
        {
            /*循环链表中只有一个结点*/
            *pNode = (node *)malloc(sizeof(struct CLinkList));
            if (!(*pNode))
                exit(0);
            (*pNode)->data = item;
            (*pNode)->next = *pNode;
        }
        else
        {
            /*找到next指向第一个结点的结点*/
            target = *pNode;
            while (target->next != *pNode)
            {
                target = target->next;
            }

            /*生成一个新的结点*/
            temp = (node *)malloc(sizeof(struct CLinkList));

            if (!temp)
                exit(0);
            // 类似尾插法
            temp->data = item;
            temp->next = *pNode;
            target->next = temp;
        }
    }
}

/*插入结点*/
/*参数：链表的第一个结点，插入的位置*/
void ds_insert(node **pNode, int i)
{
    node *temp;
    node *target;
    node *p;
    int item;
    int j = 1;

    printf("输入要插入结点的值:");
    scanf("%d", &item);

    if (i == 1)
    {
        // 新插入的结点作为第一个结点
        temp = (node *)malloc(sizeof(struct CLinkList));

        if (!temp)
            exit(0);

        /*寻找到最后一个结点*/
        target = *pNode;
        while (target->next != *pNode)
        {
            target = target->next;
        }
        temp->data = item;
        temp->next = *pNode;
        target->next = temp;
        *pNode = temp;
    }
    else
    {
        target = *pNode;

        for (; j < (i - 1); ++j)
        {
            target = target->next;
        }

        temp = (node *)malloc(sizeof(struct CLinkList));

        if (!temp)
            exit(0);

        temp->data = item;
        p = target->next;
        target->next = temp;
        temp->next = p;
    }
}

/*删除结点*/
void ds_delete(node **pNode, int i)
{
    node *target;
    node *temp;
    int j;

    if (i == 1)
    {
        // 删除的是第一个结点
        /*找到最后一个结点*/
        target = *pNode;
        while (target->next != *pNode)
        {
            target = target->next;
        }

        temp = *pNode;
        *pNode = (*pNode)->next;
        target->next = *pNode;
        free(temp);
    }
    else
    {
        // 删除其他节点
        target = *pNode;
        for (j = 1; j < i - 1; ++j)
        {
            target = target->next;
        }
        temp = target->next;
        target->next = temp->next;
        free(temp);
    }
}

/*返回结点所在位置*/
int ds_search(node *pNode, int elem)
{
    node *target;
    int i = 1;

    for (target = pNode; target->data != elem && target->next != pNode; ++i)
    {
        target = target->next;
    }

    if (target->next == pNode) /*表中不存在该元素*/
        return 0;
    else
        return i;
}

/*遍历*/
void ds_traverse(node *pNode)
{
    node *temp;
    temp = pNode;
    printf("***********链表中的元素******************\n");

    do
    {
        printf("%4d ", temp->data);
    } while ((temp = temp->next) != pNode);

    printf("\n");
}

static void MessageShow(void)
{
    printf("1.初始化链表 \n2.插入结点 \n3.删除结点 \n4.返回结点位置 \n5.遍历链表  \n0.退出 \n请选择你的操作：");
}

int main()
{
    node *pHead = NULL;
    short opp;
    int find;

    printf("----------------------------循环链表小程序--------------------\n\n");
    MessageShow();
    while (opp != '0')
    {
        scanf("%hd", &opp);
        switch (opp)
        {
        case 1:
            ds_init(&pHead);
            printf("\n");
            ds_traverse(pHead);
            break;

        case 2:
            printf("输入需要插入结点的位置: ");
            scanf("%d", &find);
            ds_insert(&pHead, find);
            printf("在位置%d插入值后：\n", find);
            ds_traverse(pHead);
            printf("\n");
            break;

        case 3:
            printf("输入需要删除的结点位置？");
            scanf("%d", &find);
            ds_delete(&pHead, find);
            printf("删除第%d个结点后:\n", find);
            ds_traverse(pHead);
            printf("\n");
            break;

        case 4:
            printf("你要查找哪个值的位置:");
            scanf("%d", &find);
            printf("元素%d所在位置：%d\n", find, ds_search(pHead, find));
            printf("\n");
            break;

        case 5:
            ds_traverse(pHead);
            printf("\n");
            break;

        case 0:
            printf("Good bye!\n");
            exit(0);
            
        default:
            printf("Please enter a available number again\n");
            MessageShow();
        }
    }

    return 0;
}
