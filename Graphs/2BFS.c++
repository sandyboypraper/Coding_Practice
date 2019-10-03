#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector <int> dfs_num(10000);

vector <vector<int>> adjlist(10000); 


int main()
{
	ll n;
	cin>>n;

	ll edge;
	cin>>edge;

	queue <int> q;

	q.push(0);

	for(ll i=0;i<edge;i++)
	{
		int a,b;
		cin>>a>>b;

		adjlist[a].push_back(b);
		// due to undirected;
		adjlist[b].push_back(a);
	}

	while(!q.empty()){
		int v = q.front(); q.pop();
		cout<<v<<" => ";
		dfs_num[v] = 1;
		for(int i = 0;i<(int)adjlist[v].size();i++)
		{
			int k = adjlist[v][i];
			if(dfs_num[k] == 0)
			{
				q.push(k);
				dfs_num[k] = 1;
			}
		}
	}
}
