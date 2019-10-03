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
		vector<ll> v(n);

		ll codd = 0;

		for(ll i = 0;i<n;i++)
		{
			cin>>v[i];
			if(v[i]%2)
				codd++;
		}

		if(codd >= k && (codd - k)%2 == 0)
		{
			cout<<"YES"<<endl;
			ll kcount = 0;
			for(ll i = 0;i<n;i++)
			{
				if(kcount == k-1)
					break;

				if(v[i]%2)
					{
						cout<<(i+1)<<" ";
						kcount++;
					}
			}

			cout<<n<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
}