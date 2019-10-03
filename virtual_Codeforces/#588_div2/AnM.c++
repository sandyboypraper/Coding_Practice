#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll n,k;
	string s;

	cin>>n>>k;
	cin>>s;

	if(n == 1 && k > 0)
	{	
		cout<<'0';
		return 0;
	}

	if(s[0] - '0' > 1 && k > 0)
	{
		s[0] = '1';
		k--;
	}

	cout<<s[0];

	for(ll i = 1;i<n;i++)
	{
		if(s[i] - '0' > 0 && k > 0)
		{
			s[i] = '0';
			k--;
		}

		cout<<s[i];
	}
}