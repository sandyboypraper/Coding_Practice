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

ll logic(ll freq[] , ll mapi[] , ll number)
{
	ll ans = 0;
	fr(i , 1 , sqrt(number))
		if(number%i == 0)
		{
			if(freq[i])
				{
					mapi[i]++; 
					ans = max(mapi[i] , ans);
				}
			if(freq[number/i] && i != number/i)
			{
				mapi[number/i]++;
				ans = max(mapi[number/i] , ans);
			}
		}
	return ans;
}

void solve()
{
	ll n;cin>>n;
	ll maxi = 0;
	ll arr[100005];clr(arr , 0);
	ll mapi[1000006];clr(mapi , 0);
	ll ans[1000006];clr(ans , 0);
	fr(i , 0 ,n-1)cin>>arr[i];
	frD(i , 0 , n-1)
	{
		maxi = max(maxi , logic(mapi , ans , arr[i]));
		mapi[arr[i]] = 1;
	}
	cout<<maxi;
}

int main()
{
	ll t;cin>>t;
	fr(i , 1, t){solve();cout<<endl;}
}