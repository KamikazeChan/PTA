#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
void PreorderTraversal( BinTree BT )
{
    if(BT==NULL)
        return;
    printf(" %d", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}
void InorderTraversal( BinTree BT )
{
    if(BT==NULL)
        return;
    InorderTraversal(BT->Left);
    printf(" %d", BT->Data);
    InorderTraversal(BT->Right);
}

BinTree Insert( BinTree BST, ElementType X )
{
    if(BST==NULL)
    {
        BST=(BinTree)malloc(sizeof(struct TNode));
        BST->Data=X;
        BST->Left=NULL;
        BST->Right=NULL;
    }
    else if(X>BST->Data)
        BST->Right=Insert(BST->Right, X);
    else
        BST->Left=Insert(BST->Left, X);
    return BST;
}
BinTree Delete( BinTree BST, ElementType X )
{
    if(BST==NULL)
    {
        printf("Not Found\n");
        return BST;
    }
    BinTree deletedNode, parentNode=BST;
    if(parentNode->Data==X)
    {
        parentNode=NULL;
        deletedNode=BST;
    }
    else
    {
        if(parentNode->Data>X)
            deletedNode=parentNode->Left;
        else
            deletedNode=parentNode->Right;
        while (deletedNode!=NULL && deletedNode->Data!=X)
        {
            parentNode=deletedNode;
            if(deletedNode->Data>X)
                deletedNode=deletedNode->Left;
            else
                deletedNode=deletedNode->Right;
        }
        if(deletedNode==NULL)
        {
            printf("Not Found\n");
            return BST;
        }
    }
    if(deletedNode->Left==NULL && deletedNode->Right==NULL)
    {
        if(parentNode!=NULL)
            if(parentNode->Right==deletedNode)
                parentNode->Right=NULL;
            else
                parentNode->Left=NULL;
        else
            BST=NULL;
        free(deletedNode);
    }
    else if(deletedNode->Left==NULL)
    {
        if(parentNode!=NULL)
            if(parentNode->Right==deletedNode)
                parentNode->Right=deletedNode->Right;
            else
                parentNode->Left=deletedNode->Right;
        else
            BST=BST->Right;
        free(deletedNode);
    }
    else if(deletedNode->Right==NULL)
    {
        if(parentNode!=NULL)
            if(parentNode->Right==deletedNode)
                parentNode->Right=deletedNode->Left;
            else
                parentNode->Left=deletedNode->Left;
        else
            BST=BST->Left;
        free(deletedNode);
    }
    else
    {
        BinTree newNode=FindMax(deletedNode->Left);
        deletedNode->Data=newNode->Data;
        deletedNode->Left=Delete(deletedNode->Left, newNode->Data);
    }
    return BST;
}
Position Find( BinTree BST, ElementType X )
{
    if(BST==NULL)
        return NULL;
    if(BST->Data==X)
        return BST;
    else if(BST->Data>X)
        return Find(BST->Left, X);
    else
        return Find(BST->Right, X);
}
Position FindMin( BinTree BST )
{
    if(BST==NULL)
        return NULL;
    while(BST->Left!=NULL)
        BST=BST->Left;
    return BST;
}
Position FindMax( BinTree BST )
{
    if(BST==NULL)
        return NULL;
    while(BST->Right!=NULL)
        BST=BST->Right;
    return BST;
}