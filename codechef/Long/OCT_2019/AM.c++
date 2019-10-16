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

// N = 7
// 0 1 2 3 4 5 6
//a = i%N  b = N - 

// 1 1 1 0 0 0 1 0 0
// 0 0 1 1 1 0 1 0 1
// 1 1 0 1 1 0 0 0 1
// 1 1 1 0 0 0 1 0 0
// 0 0 1 1 1 0 1 0 1

void solve()
{
	ll n;cin>>n;
	ll k;cin>>k;
	ll limit = (k-1)%n;
	ll bar = (k + n -1)/n;
	ll arr[10004];clr(arr , 0);
	ll ans[10004];clr(ans , 0);
	fr(i ,0, n-1)cin>>arr[i];
	fr(i ,0, n-1)
	{
		ll inda = i,indb = n - i - 1;
		ll ta = arr[inda];
		ll tb = arr[indb];


		ll ca = (inda <= limit)?bar:(bar-1);

		if(ta == tb && ca > 0)
			{
				ans[inda] = 0;
				continue;
			}

		ca = ca%3;

		if(indb >= inda)
		{
			if(ca == 1)
			ans[inda] = ta^tb;
			else if(ca == 2)
			ans[inda] = tb;
			else
			ans[inda] = ta;
		}
		else{
			if(ca == 1)
				ans[inda] = tb;
			else if(ca == 2)
				ans[inda] = ta^tb;
			else
				ans[inda] = ta;
		}
		
	}
	fr(i , 0 , min(n-1 , k-1))
	cout<<ans[i]<<" ";
	fr(i , min(n-1 , k - 1)+1 , n -1)
	cout<<arr[i]<<" ";
}

int main()
{
	ll t;cin>>t;
	fr(i , 1 , t)
	{
		solve();
		cout<<endl;
	}
}