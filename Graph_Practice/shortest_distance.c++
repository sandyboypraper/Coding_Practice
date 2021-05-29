#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<vector<pair<int ,int>>> AdjList(1000);
vector<int> Visited(1000, 0);

void shortestPath(int u){
    priority_queue<pair<int,int>> pq;
    pq.push({u,0});
    vector<int> dist(1000, 20000)
    dist[u] = 0;
    while(!pq.empty())
    {
        int w = pq.front().first;
        int v = pq.front().second;
        pq.pop();

        for(int i = 0;i<AdjList[v].size();i++)
        {
            pq.insert(AdjList[v][i]);
        }
    }
}

int main()
{
    int n,m;cin>>n>>m;
    for(int i = 0;i<m;i++);
    {
        int a,b,w;cin>>a>>b>>w;
        AdjList[a].push_back({w,b});
    }

    cout<<shortestPath(0);
}