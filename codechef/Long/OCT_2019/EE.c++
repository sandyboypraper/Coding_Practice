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

void solve()
{
	ll n,m;cin>>n>>m;
	vector<vector<ll>> Adjlist(n+1);
	vector<ll> degree(n+1 , 0);
	ll isodd = 0;
	ll one,two;

	fr(i , 1 , m)
	{
		ll a,b;cin>>a>>b;
		if(i == 1)
		{
			one = a;two = b;
		}
		Adjlist[a].push_back(b);Adjlist[b].push_back(a);
		degree[a]++;degree[b]++;
	}

	if(m%2==0)
	{
		cout<<1<<endl;
		fr(i , 1 , n)cout<<1<<" ";
		return;
	}

	ll minOdd;
	fr(i , 1 , n)if(degree[i]%2 != 0){isodd = 1;minOdd = i;break;}

	if(isodd)
	{
		cout<<2<<endl;
		fr(i , 1 , n)
		{
			if(i == minOdd)
				cout<<2<<" ";
			else
				cout<<1<<" ";
		}

		return;
	}

	cout<<3<<endl;
	fr(i , 1 ,n)
	{
		if(i == one)
			cout<<1<<" ";
		else if(i == two)
			cout<<2<<" ";
		else
			cout<<3<<" ";
	}

}

int main()
{
	ll t;
	cin>>t;
	fr(i , 1 , t)
	solve(),cout<<endl;
}