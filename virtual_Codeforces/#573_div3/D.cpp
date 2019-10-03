#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll incCountR(ll ind , char c)
{
	ind = ind%3;
	char cc = 'R';
	if(ind == 0)
		cc = 'R';
	else if(ind == 1)
		cc = 'G';
	else
		cc = 'B';

	return c != cc;
}

ll incCountG(ll ind , char c)
{
	ind = ind%3;
	char cc = 'G';
	if(ind == 0)
		cc = 'G';
	else if(ind == 1)
		cc = 'B';
	else
		cc = 'R';

	return c != cc;
}

ll incCountB(ll ind , char c)
{
	ind = ind%3;
	char cc = 'B';
	if(ind == 0)
		cc = 'B';
	else if(ind == 1)
		cc = 'R';
	else
		cc = 'G';

	return c != cc;
}

int main()
{
	ll t;
	cin>>t;

	while(t--)
	{
		ll n,k;
		cin>>n>>k;

		string s;
		cin>>s;

		ll mini = 10000000;

		for(ll i = 0;i<=(n-k);i++)
		{
			ll countR = 0;
			ll countG = 0;
			ll countB = 0;
			for(ll j = i;j<(i+k);j++)
			{
				ll ind = j-i;
				char c  = s[j];
				countR += incCountR(ind, c);
				countG += incCountG(ind, c);
				countB += incCountB(ind, c);

				// cout<<countR<<" "<<countG<<" "<<countB<<endl;
			}

			mini = min(mini , countR);
			mini = min(mini , countB);
			mini = min(mini , countG);
		}

		cout<<mini<<endl;
	}
}