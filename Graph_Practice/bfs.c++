#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<vector<int>> AdjList(1000);

int main()
{
    ll n,m;cin>>n>>m;

    for(int i = 0;i<m;i++)
    {
        int a,b;cin>>a>>b;
        AdjList[a].push_back(b);
        AdjList[b].push_back(a);
    }    

    queue<int> q;
    vector<int> Visited(1000, 0);
    q.push(0);
    Visited[0] = 1;
    while(!q.empty())
    {
        int v = q.front();q.pop();
        cout<<v<<" ";
        for(int i = 0;i<AdjList[v].size();i++)
        {
            if(Visited[AdjList[v][i]] == 0)
               {
                   Visited[AdjList[v][i]] = 1;
                   q.push(AdjList[v][i]);
               } 
        }
    }
}