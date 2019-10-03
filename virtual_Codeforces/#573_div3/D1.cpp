#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct RGB{
	long long int R;
	long long int G;
	long long int B;
};


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

		vector <RGB> v;

		v.push_back(RGB());

		v[0].R = 0;
		v[0].G = 0;
		v[0].B = 0;


		ll mincount = 10000000;

		for(ll i = 1;i<=n;i++)
		{
			v.push_back(RGB());
			v[i].R = v[i-1].R + incCountR(i-1 , s[i-1]);
			v[i].G = v[i-1].G + incCountG(i-1 , s[i-1]);
			v[i].B = v[i-1].B + incCountB(i-1 , s[i-1]);

			if(i >= k)
			{
				mincount = min(v[i].R - v[i-k].R , mincount);
				mincount = min(v[i].G - v[i-k].G , mincount);
				mincount = min(v[i].B - v[i-k].B , mincount);
			}
 		}

 		cout<<mincount<<endl;
	}
}