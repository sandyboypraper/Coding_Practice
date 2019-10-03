#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll q;
	cin>>q;

	while(q--)
	{
		ll n,k;
		cin>>n>>k;

		ll mini = 1000000000;
		ll maxi = 0;

		for(ll i = 0;i<n;i++)
		{
			ll a;
			cin>>a;

			mini = min(a,mini);
			maxi = max(a , maxi);
		}

		if(mini + k >= maxi - k)
		{
			cout<<mini+k<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}

	}
}