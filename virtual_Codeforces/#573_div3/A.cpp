#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll q;
	cin>>q;

	while(q--)
	{
		vector<ll> v(3);
		for(int i = 0;i<3;i++)
			cin>>v[i];

		sort(v.begin() , v.end());

		ll a = v[0];
		ll b = v[1];
		ll c = v[2];

		ll d = b-a;
		ll mx = c - d;

		cout<<(a + d + mx/2)<<endl;
	}
}