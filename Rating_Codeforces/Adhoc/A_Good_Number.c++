#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int isKgood(string s , ll k)
{
	string ss = "0123456789";
	int c = 0, cc = 0;

	for(int i = 0;i<=k;i++)
	{
		int a = s.find(ss[i]);
		if(a != -1)
		{
			c++;
			a = -1;
		}
	}

	if(c >= k+1)
		return 1;

	return 0;
}

int main()
{
	ll k,n;
	cin>>n>>k;

	ll ans = 0;

	for(int i = 0; i< n ; i++)
	{
		string s;
		cin>>s;

		if(isKgood(s , k))
			ans++;
	}

	cout<<ans;
}