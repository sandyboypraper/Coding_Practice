#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll fact[10000007],fact_inv[103];

ll Mod = 1000000007;

ll modexpo(ll x,ll n)
{
	ll ans = 1;
	while(n>0)
	{
		if(n%2 == 1)
		{
			ans = (ans*x)%Mod;
		}
		x = (x*x)%Mod;
		n = n/2;
	}
	return ans;
}

void fill_fact()
{
	for(ll i = 1;i<10000005;i++)
	{
		fact[i] = (i*fact[i-1])%Mod;
	}
	for(ll i = 1;i<101;i++)
	{
		fact_inv[i] = modexpo(fact[i] , Mod - 2);
	}
}

int main()
{
	fact[0] = 1;
	fact_inv[0] = 1;
	fill_fact();

	ll k;cin>>k;
	ll arr[k];
	ll sum = 0;

	for(ll i = 0;i<k;i++)
	{
		cin>>arr[i];
		sum = sum + arr[i];
	}

	sum -= k;
	ll ans = fact[sum];

	for(ll i = 0;i<k;i++)
	{
		if(arr[i]!=1)
		{
			ans = (ans*fact_inv[arr[i] - 1])%Mod;
			ans = ans%Mod;
		}
	}

	cout<<ans;
}