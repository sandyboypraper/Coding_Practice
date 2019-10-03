#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll a,b,c,d;
	cin>>a>>b>>c>>d;

	ll btemp = 0;

	ll sum = a+b+c+d;
	
	vector<ll> vv = {a,b,c,d};
	sort(vv.begin() , vv.end());

	if(sum&1)
	{
		cout<<"NO";
		return 0;
	}

	sum /= 2;
	ll temp = 0;
	ll init = 0;

	for(ll i = 0;i<4;i++)
	{
		if(temp == sum)
		{
			cout<<"YES";
			return 0;
		}
		temp += vv[i];
		
		if(temp > sum)
		{
			temp -= vv[init];
			init++;
		}
	}

	cout<<"NO";
}