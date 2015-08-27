#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item{
    int coe;
    int exp;
};
bool compare(Item item1, Item item2)
{
    return item1.exp>item2.exp;  //从大到小
}
void print(vector<Item> vecRes)
{
    vector<Item>::iterator it1, it2;
    bool flag=0;
    sort(vecRes.begin(), vecRes.end(), compare);

    for(it1=vecRes.begin(); it1<vecRes.end(); it1=it2)
    {
        for(it2=it1+1; it2<vecRes.end() && it2->exp==it1->exp; it2++)
        {
            it1->coe+=it2->coe;
        }
        if(it1->coe!=0)
        {
            if(flag==1)
                cout<<" ";
            flag=1;
            cout << it1->coe << " " << it1->exp;
        }
    }
    if(flag==0)//包括vecRes.size()==0
        cout<<"0 0";
}
int main()
{
    vector<Item> vec1, vec2, vecSum, vecMul;
    vector<Item>::iterator it1, it2;

    int N1, N2;
    Item temp;

    cin>>N1;
    for(int i=0; i<N1; i++)
    {
        cin>>temp.coe>>temp.exp;
        vec1.push_back(temp);
    }
    cin>>N2;
    for(int i=0; i<N2; i++)
    {
        cin>>temp.coe>>temp.exp;
        vec2.push_back(temp);
    }

    for(it1=vec1.begin();it1<vec1.end();it1++)
    {
        for(it2=vec2.begin();it2<vec2.end();it2++)
        {
            temp.coe=it1->coe*it2->coe;
            temp.exp=it1->exp+it2->exp;
            vecMul.push_back(temp);
        }
    }

    print(vecMul);
    cout<<endl;

    for(it1=vec1.begin();it1!=vec1.end();it1++)
        vecSum.push_back(*it1);
    for(it2=vec2.begin();it2!=vec2.end();it2++)
        vecSum.push_back(*it2);

    print(vecSum);
}
