/*二叉树的二叉线索存储结构定义*/

typedef int TElemType;
typedef enum{Link,Thread} PointerTag;//枚举列表自动定1和0，为0时指向孩子，为1时指向线索
typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode *lchild,*rchild;
    PointerTag Ltag;
    PointerTag Rtag;
}BiThrNode,*BiThrTree;
