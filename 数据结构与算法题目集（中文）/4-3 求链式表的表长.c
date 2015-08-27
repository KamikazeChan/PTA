#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
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
int Length( List L )
{
    int l=0;
    while(L!=NULL)
    {
        l++;
        L=L->Next;
    }
    return l;
}