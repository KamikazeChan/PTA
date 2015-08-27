#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
//typedef enum { false, true } bool;
typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize );
bool Push( Stack S, ElementType X, int Tag );
ElementType Pop( Stack S, int Tag );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Tag ); /* details omitted */

int main()
{
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
            case push:
                scanf("%d %d", &Tag, &X);
                if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
                break;
            case pop:
                scanf("%d", &Tag);
                X = Pop(S, Tag);
                if ( X==ERROR ) printf("Stack %d is Empty!\n", Tag);
                break;
            case end:
                PrintStack(S, 1);
                PrintStack(S, 2);
                done = 1;
                break;
        }
    }
    return 0;
}
Stack CreateStack( int MaxSize )
{
    Stack S=(Stack)malloc(sizeof(struct SNode));
    S->MaxSize=MaxSize;
    S->Top1=-1;
    S->Top2=S->MaxSize;
    S->Data=(ElementType*)malloc(sizeof(ElementType)*MaxSize);
    return S;
}
bool Push( Stack S, ElementType X, int Tag )
{
    if(S->Top2-S->Top1==1)
    {
        printf("Stack Full\n");
        return false;
    }
    if(Tag==1)
        S->Data[++S->Top1]=X;
    else
        S->Data[--S->Top2]=X;
    return true;
}
ElementType Pop( Stack S, int Tag )
{
    if(Tag==1)
    {
        if(S->Top1==-1)
        {
            printf("Stack 1 Empty\n");
            return ERROR;
        }
        else
            return S->Data[S->Top1--];
    }
    else if(Tag==2)
    {
        if(S->Top2==S->MaxSize)
        {
            printf("Stack 2 Empty\n");
            return ERROR;
        }
        else
            return S->Data[S->Top2++];
    }
}
Operation GetOp()
{
    char op[5];
    scanf("%s",op);
    switch (op[2])
    {
        case 's':
            return push;
        case 'p':
            return pop;
        case 'd':
            return end;
    }
}
void PrintStack( Stack S, int Tag )
{
    printf("Pop from Stack %d:", Tag);
    int i;
    if(Tag==1)
    {
        int i=S->Top1;
        while (i>=0)
            printf(" %d", S->Data[i--]);
        printf("\n");
    }
    else if(Tag==2)
    {
        int i=S->Top2;
        while (i<S->MaxSize)
            printf(" %d", S->Data[i++]);
        printf("\n");
    }
}