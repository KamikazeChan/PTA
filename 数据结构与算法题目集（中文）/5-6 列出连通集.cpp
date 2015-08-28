#include <iostream>
#include <vector>

using namespace std;
void DFS(int Graph[][10], bool Flag[], int i, int N)
{
    Flag[i]=true;
    cout<<i<<" ";
    for(int j=0; j<N; j++)
    {
        if(Graph[i][j]==1 && Flag[j]==false)
            DFS(Graph, Flag, j, N);
    }
}
void BFS(int Graph[][10], bool Flag[], int i, int N)
{
    vector<int>vec;
    vector<int>::iterator it1;
    for(int j=0; j<N; j++)
    {
        if(Graph[i][j]==1 && Flag[j]==false)
        {
            Flag[j] = true;
            cout << j << " ";
            vec.push_back(j);
        }
    }
    for(it1=vec.begin(); it1<vec.end(); it1++)
        BFS(Graph, Flag, *it1, N);
}
int main()
{
    int N, E, a, b;
    int Graph[10][10]={0};
    bool Flag[10]={false};
    cin>>N>>E;
    for(int i=0; i<E; i++)
    {
        cin>>a>>b;
        Graph[a][b]=1;
        Graph[b][a]=1;
    }

    for(int i=0; i<N; i++)
    {
        if(!Flag[i])
        {
            cout<<"{ ";
            DFS(Graph, Flag, i, N);
            cout<<"}\n";
        }
    }
    for(int i=0; i<N; i++)
        Flag[i]=false;
    for(int i=0; i<N; i++)
    {
        if(!Flag[i])
        {
            cout<<"{ "<< i << " ";
            Flag[i] = true;
            BFS(Graph, Flag, i, N);
            cout<<"}\n";
        }
    }
    return 0;
}

