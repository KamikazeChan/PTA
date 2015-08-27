#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(BinTree BT); /* ÊµÏÖÏ¸½ÚºöÂÔ */
void PreorderPrintLeaves( BinTree BT );

int main()
{
    BinTree BT = NULL;
    BT=CreatBinTree(BT);
    printf("Leaf nodes are:");
    PreorderPrintLeaves(BT);
    printf("\n");

    return 0;
}
BinTree CreatBinTree(BinTree BT)
{
    char ch=getchar();
    if(ch==' ')
        BT=NULL;
    else {
        BT = (BinTree) malloc(sizeof(struct TNode));
        BT->Data = ch;
        BT->Left = CreatBinTree(BT->Left);
        BT->Right = CreatBinTree(BT->Right);
    }
    return BT;
}
void PreorderPrintLeaves( BinTree BT )
{
    if(BT==NULL)
        return;
    if(BT->Left==NULL && BT->Right==NULL)
        printf(" %c", BT->Data);
    PreorderPrintLeaves(BT->Left);
    PreorderPrintLeaves(BT->Right);
}