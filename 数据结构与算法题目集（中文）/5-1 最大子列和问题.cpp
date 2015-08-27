#include <iostream>
using namespace std;
//on-line algorithm
int main()
{
    int K, X, ThisSum=0, MaxSum=0;
    cin>>K;
    for(int i=0; i<K; i++)
    {
        cin>>X;
        ThisSum+=X;
        if(ThisSum>MaxSum)
            MaxSum=ThisSum;
        else if(ThisSum<0)
            ThisSum=0;
    }
    cout<<MaxSum;
}
