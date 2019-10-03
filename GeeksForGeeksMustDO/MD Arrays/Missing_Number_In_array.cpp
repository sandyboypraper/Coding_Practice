#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;

		vector<int> v(n-1);

		ll sum = 0;
		ll sum1 = (n*(n+1))/2;

		for(int i = 0;i<n-1;i++)
		{
			cin>>v[i];
			sum += v[i];
		}

		cout<<sum1-sum<<endl;
	}
}