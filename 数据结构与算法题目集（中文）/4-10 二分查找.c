#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch( List Tbl, ElementType K );

int main()
{
    List Tbl;
    ElementType K;
    Position P;

    Tbl = ReadInput();
    scanf("%d", &K);
    P = BinarySearch( Tbl, K );
    printf("%d\n", P);

    return 0;
}

List ReadInput()
{
    int n;
    scanf("%d", &n);
    List L=(List)malloc(sizeof(struct LNode));
    for(int i=0; i<n; i++)
        scanf("%d", &L->Data[i+1]);
    L->Last=n;
}
Position BinarySearch( List Tbl, ElementType K )
{
    int left=1, right=Tbl->Last;
    int middle=(left+right)/2;
    while (Tbl->Data[middle]!=K)
    {
        if(left==right)
            break;
        if(Tbl->Data[middle]>K)
            right=middle-1;
        else
            left=middle+1;
        middle=(left+right)/2;
    }
    if(Tbl->Data[middle]!=K)
        return NotFound;
    else
        return middle;
}