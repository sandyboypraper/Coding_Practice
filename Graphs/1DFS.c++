#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector <int> dfs_num(10000);

vector <vector<int>> adjlist(10000); 

void dfs(int u)
{
       dfs_num[u]  =  1;
       cout<<u<<" => ";
       for(int j=0;j<(int)adjlist[u].size();j++)
           {
                int v = adjlist[u][j];
                if(dfs_num[v]==0)
                   dfs(v);
           }
}

int main()
{
	ll n;
	cin>>n;

	ll edge;
	cin>>edge;


	for(ll i=0;i<edge;i++)
	{
		int a,b;
		cin>>a>>b;

		adjlist[a].push_back(b);
		// due to undirected;
		adjlist[b].push_back(a);
	}

	dfs(0);
}
