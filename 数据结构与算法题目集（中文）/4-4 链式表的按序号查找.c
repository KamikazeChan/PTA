#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

List Read()
{
    int n, flag=0;
    scanf("%d", &n);
    List head, lastNode;
    while(n>=0)
    {
        List thisNode=(List)malloc(sizeof(LNode));
        thisNode->Data=n;
        thisNode->Next=NULL;
        if(flag==0)
        {
            head = thisNode;
            flag=1;
        }
        else
            lastNode->Next=thisNode;
        lastNode=thisNode;
        scanf("%d", &n);
    }
    return head;
}
ElementType FindKth( List L, int K )
{
    int i=1;
    if(K<=0)
        return ERROR;
    while(L!=NULL && i<K)
    {
        L=L->Next;
        i++;
    }
    if(L!=NULL)
        return L->Data;
    else
        return ERROR;
}