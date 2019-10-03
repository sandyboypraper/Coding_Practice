#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct pointR{
	ll a;
	ll b;
	ll l;
	ll t;
	ll r;
	ll b;
};

int main()
{
	ll q;
	cin>>q;

	while(q--)
	{
		ll n;
		cin>>n;

		vector<pointR> p(n);

		for(ll i = 0;i<n;i++)
		{
			cin>>p[i].a>>p[i].b>>p[i].l>>p[i].t>>p[i].r>>p[i].b;
			
		}
	}
}