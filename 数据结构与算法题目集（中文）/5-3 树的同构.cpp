#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    char ch;
    char child1, child2;
    char parent;
};

int main()
{
    vector<Node> vec1, vec2;
    vector<Node>::iterator it1, it2;

    int N1, N2;
    Node temp;

    cin>>N1;
    for(int i=0; i<N1; i++)
    {
        cin>>temp.ch>>temp.child1>>temp.child2;
        vec1.push_back(temp);
    }
    cin>>N2;
    for(int i=0; i<N2; i++)
    {
        cin>>temp.ch>>temp.child1>>temp.child2;
        vec2.push_back(temp);
    }
    
    for(it1=vec1.begin(); it1!=vec1.end(); it1++)
    {
        for(it2=vec1.begin(); it2!=vec1.end(); it2++)
        {
            if(it2->child1==it1-vec1.begin()+'0' || it2->child2==it1-vec1.begin()+'0')
            {
                it1->parent=it2->ch;
                break;
            }
            it1->parent=' ';
        }
    }

    for(it1=vec2.begin(); it1!=vec2.end(); it1++)
    {
        for(it2=vec2.begin(); it2!=vec2.end(); it2++)
        {
            if(it2->child1==it1-vec2.begin()+'0' || it2->child2==it1-vec2.begin()+'0')
            {
                it1->parent=it2->ch;
                break;
            }
            it1->parent=' ';
        }
    }

    for(it1=vec1.begin(); it1!=vec1.end(); it1++)
    {
        for(it2=vec2.begin(); it2!=vec2.end(); it2++)
        {
            if(it1->ch==it2->ch)
            {
                if(it1->parent!=it2->parent)
                {
                    printf("No");
                    return 0;
                }
                break;
            }
        }
        if(it2==vec2.end())
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}
