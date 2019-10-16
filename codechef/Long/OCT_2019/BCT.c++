#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll; 

#define fr(i ,init , fin) for(int i = init;i<=fin;i++)
#define frD(i ,init , fin) for(int i = fin;i>=init;i--)
#define exp(a , x) for(auto& a : x)
#define clr(a , b) memset(a , b , sizeof(a))

#define printmat(a , row , col) for(int i = 0;i<row;i++){for(int j = 0;j<col;j++)cout<<a[i][j]<<" ";cout<<endl;}

vector<vector<ll>> Adjlist(500005);
vector<ll> values(500005);
vector<vector<pair<ll , ll>>> insertion(500005);
vector<bool> isLeef(500005 , false);
vector<ll> parent(500005);
vector<bool> visited(500005 , false);

// parent
// isLeef
void bfs()
{
	queue<ll> q;
	q.push(1);
	visited[1] = true;
	if(Adjlist[1].size() == 0)
		{
			isLeef[1] = true;
			return;
		}

	while(!q.empty())
	{
		ll u = q.front();q.pop();
		if(u != 1 && Adjlist[u].size() == 1)
			isLeef[u] = true;
		fr(i , 0 , Adjlist[u].size() - 1)
		{
			ll v = Adjlist[u][i];
			if(!visited[v])
			{
			   visited[v] = true;
			   parent[v] = u;
			   q.push(v);
			}
		}
	}
}

ll findval(ll node , ll timeline , bool forLeef)
{

	if(isLeef[node])
		return values[node];

	if(forLeef)
	{
		ll temp = 0;
		fr(i , 0 , insertion[node].size() - 1)
		{
			if(insertion[node][i].first <= timeline)
				temp += insertion[node][i].second;
		}
		return temp;
	}

	fr(i , 0 , insertion[node].size() - 1)
	{
		if(insertion[node][i].first == timeline)
			return insertion[node][i].second;
	}

	return 0;
}

ll findans(ll aa , ll timeline , bool forLeef)
{
	ll temp = findval(aa , timeline , forLeef);
	if(parent[aa] == 0)
		return temp;

	temp += findans(parent[aa] , timeline - 1 , forLeef);
	return temp;
}

int main()
{
	ll n,q;cin>>n>>q;
	fr(i , 1 , n-1){ll a,b;cin>>a>>b;Adjlist[a].push_back(b);Adjlist[b].push_back(a);}
	fr(i , 1 , n){
		ll aaa;cin>>aaa;
		values[i] = aaa;
		insertion[i].push_back({0 , aaa});
	}
	// cout<<"hey"<<endl;
	ll timeline = 1;
	parent[1] = 0;

	// if(n==1)
	//  	isLeef[1] = true;
	// else
	 	bfs();

	 // if(n == 2)
	 // 	isLeef[1] = false;

	while(q--)
	{
		char c;cin>>c;
		if(c == '?')
		{
			ll aa;cin>>aa;
			if(isLeef[aa])
				cout<<findans(aa , timeline , true)<<endl;
			else
				cout<<findans(aa , timeline , false)<<endl;
		}
		else
		{
			ll aa,bb;cin>>aa>>bb;
			insertion[aa].push_back({timeline , bb});
			if(isLeef[aa])
				values[aa] += bb;
		}
		timeline++;
	}
}