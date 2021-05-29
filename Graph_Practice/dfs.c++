#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<vector<int>> AdjList(1000);
vector<int> Visited(1000, 0);

void dfs(int u)
{
    cout<<u<<" ";

    Visited[u] = 1;

    for(int i = 0;i < (int)AdjList[u].size();i++)
    {
        int v = AdjList[u][i];
        if(Visited[v] == 0)
            dfs(v);
    }
}

int main()
{
    ll n,m;cin>>n>>m;

    for(int i = 0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }    

    dfs(0);
}