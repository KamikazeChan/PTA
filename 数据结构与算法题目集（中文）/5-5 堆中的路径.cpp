#include <iostream>
#include <stdlib.h>
//通过插入建堆
using namespace std;
typedef struct BinHeapStruct *BinHeap;

BinHeap BinHeapInitialize( int size );
void PercolateUp( int A[], int i );

struct BinHeapStruct{
    int Size;
    int *Elements;
};

int main()
{
    int N, M, index;

    cin>>N>>M;
    BinHeap H=BinHeapInitialize(N);
    for(int i=0; i<N; i++)
    {
        cin>>H->Elements[i+1];
        PercolateUp(H->Elements, i+1);
    }

    for(int j=0; j<M; j++)
    {
        cin>>index;
        while(index!=0)
        {
            cout<<H->Elements[index];
            if(index!=1)
                cout<<" ";
            index/=2;
        }
        cout<<endl;
    }
    return 0;
}

void PercolateUp( int A[], int i ) {
    int Child, Parent=i;
    int Tmp=A[i];
    for (Child = Parent; Child != 1; Child = Parent) {
        Parent = Child / 2;
        if (A[Parent] > Tmp)
            A[Child] = A[Parent];
        else
            break;
    }
    A[Child] = Tmp;
}

BinHeap BinHeapInitialize( int size ) {
    BinHeap H;
    H = (BinHeap) malloc(sizeof(struct BinHeapStruct));
    H->Elements = (int *) malloc((size + 1) * sizeof(int));
    H->Size = size;

    return H;
}
