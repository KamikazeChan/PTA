#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    int Data;
    BinTree Left;
    BinTree Right;
};
BinTree Insert( BinTree BST, int X )
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
bool check(BinTree T1, BinTree T2)
{
    if(T1==NULL && T2==NULL)
        return true;
    else if(T1==NULL || T2==NULL)
        return false;
    else if(T1->Data!=T2->Data)
        return false;
    else
        return check(T1->Left, T2->Left)&&check(T1->Right, T2->Right);
}
int main()
{
    int N, L, X;
    BinTree temp=NULL;
    vector<BinTree> vecBST;
    vector<BinTree>::iterator it1;
    cin>>N;
    while (N!=0)
    {
        cin>>L;
        for(int i=0; i<=L; i++)
        {
            for(int j=0; j<N; j++)
            {
                cin>>X;
                temp=Insert(temp, X);
            }
            vecBST.push_back(temp);
            temp=NULL;
        }
        for(it1=vecBST.begin()+1; it1!=vecBST.end(); it1++)
        {
            if(check(*vecBST.begin(),*it1)== true)
                printf("Yes\n");
            else
                printf("No\n");
        }

        vecBST.clear();
        cin>>N;
    }

    return 0;
}
