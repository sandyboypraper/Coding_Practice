#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll; 

#define fr(init , fin) for(int i = init;i<=fin;i++)
#define frD(init , fin) for(int i = fin;i>=init;i--)
#define exp(a , x) for(auto& a : x)
#define clr(a , b) memset(a , b , sizeof(a))

#define printmat(a , row , col) for(int i = 0;i<row;i++){for(int j = 0;j<col;j++)cout<<a[i][j]<<" ";cout<<endl;}

int main()
{
	ll n,k;
	cin>>n>>k;
	queue<ll> qq;
	map<ll,ll> mapi;
	fr(1,n){
		ll a;cin>>a;
		if(!mapi[a])
		{
			mapi[a]= 1;
			qq.push(a);
		}
		if(qq.size()>k)
			{
				mapi[qq.front()] = 0;
				qq.pop();
			}
	}
	cout<<qq.size()<<endl;
	vll ans;
		while(!qq.empty())
			ans.push_back(qq.front()),qq.pop();

		frD(0 , ans.size() - 1)cout<<ans[i]<<" ";
}