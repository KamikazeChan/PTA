#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read();
void Print( List L ); 

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}
List Read()
{
    int n;
    scanf("%d", &n);
    List head, lastNode;
    for(int i=0; i<n; i++)
    {
        List thisNode=(List)malloc(sizeof(Node));
        scanf("%d", &thisNode->Data);
        thisNode->Next=NULL;
        if(i==0)
            head=thisNode;
        else
            lastNode->Next=thisNode;
        lastNode=thisNode;
    }
    return head;
}
void Print( List L )
{
    while(L!=NULL)
    {
        printf("%d", L->Data);
        L=L->Next;
        if(L!=NULL)
            printf(" ");
        else
            printf("\n");
    }
}
List Reverse( List L )
{
    List lastNode, thisNode, nextNode;
    lastNode=NULL;
    thisNode=L;
    while(thisNode!=NULL)
    {
        nextNode=thisNode->Next;
        thisNode->Next=lastNode;
        lastNode=thisNode;
        thisNode=nextNode;
    }
    return lastNode;
}