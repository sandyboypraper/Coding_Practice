#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll t;
	cin>>t;

	while(t--)
	{
		ll n,q;
		cin>>n>>q;

		vector<ll> B(n);
		for(ll i = 1;i<=n-1;i++)
			cin>>B[i];

		vector<ll> psum(n);
		psum[0] = 0;

		for(ll i = 1;i<=n-1;i++)
		 {
		 	psum[i] = psum[i-1] + ((i&1)?1:-1)*B[i];
		 	
		 }

		while(q--)
		{
			ll a,b;cin>>a>>b;
			ll mini = min(a,b);
			ll maxi = max(a,b);
			
			if((maxi - mini - 1)&1)
			{
				cout<<"UNKNOWN"<<endl;
				continue;
			}

			// cout<<maxi<<" "<<mini<<endl;
			// cout<<psum[maxi - 1]<<"  "<<psum[mini - 1]<<endl;


			if(maxi == mini + 1)
			{
				cout<<B[mini]<<endl;
				continue;
			}

			ll ans = psum[maxi - 1] - psum[mini - 1];
			if(mini&1)
				cout<<ans<<endl;
			else
				cout<<-ans<<endl;
		}
	}
}