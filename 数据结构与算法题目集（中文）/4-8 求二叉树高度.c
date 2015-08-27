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

BinTree CreatBinTree(BinTree BT);
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = NULL;
    BT = CreatBinTree(BT);
    printf("%d\n", GetHeight(BT));
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
int GetHeight( BinTree BT )
{
    if(BT==NULL)
        return 0;

    int leftHeight=GetHeight(BT->Left);
    int rightHeight=GetHeight(BT->Right);
    if(leftHeight>rightHeight)
        return leftHeight+1;
    else
        return rightHeight+1;
}