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
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = NULL;
    BT=CreatBinTree(BT);
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
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
void InorderTraversal( BinTree BT )
{
    if(BT==NULL)
        return;
    InorderTraversal(BT->Left);
    printf(" %c", BT->Data);
    InorderTraversal(BT->Right);
}
void PreorderTraversal( BinTree BT )
{
    if(BT==NULL)
        return;
    printf(" %c", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}
void PostorderTraversal( BinTree BT )
{
    if(BT==NULL)
        return;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %c", BT->Data);
}
void LevelorderTraversal( BinTree BT )
{
    if(BT==NULL)
        return;
    BinTree Q[1000];
    int front=0, rear=1;
    Q[0]=BT;
    while(front<rear)
    {
        if(Q[front]->Left!=NULL)
            Q[rear++]=Q[front]->Left;
        if(Q[front]->Right!=NULL)
            Q[rear++]=Q[front]->Right;
        printf(" %c", Q[front++]->Data);
    }
}
