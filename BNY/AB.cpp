#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

map<ll ,ll> m;

ll a[1000006], aa[1000006];

map<ll ,ll> mb;

ll ii = 0,jj = 0;

ll ans = INT_MAX;

ll uu = 0;

void minsert(ll x)
{
	map<ll ,ll> :: iterator it;
	it = m.find(x);
	if(it != m.end())
	{
		(*it).second = (*it).second + 1;
	}
	else
	{
		m.insert(pair<ll,ll>(x,1));
		uu++;
	}
}

void extrct(ll x)
{
	map<ll ,ll> :: iterator it;
	it = m.find(x);
	if(it != m.end())
	{
		if((*it).second == 1)
		{
			m.erase(x);
			uu--;
		}
		else
		{
			(*it).second = (*it).second - 1;
		}
	}
}

void incj()
{
	jj++;
}

void inci(ll k)
{
	while(uu >= k)
	{
		if(aa[ii] == 1)
			extrct(a[ii]);
		ii++;
	}

	ii--;
	minsert(a[ii]);
}


int main()
{
		ll n,m,k;
	cin>>n>>m>>k;
	map <ll , ll> :: iterator it;

	for(ll i = 0;i<n;i++)
	{
		cin>>a[i];
	}

	for(ll i = 0;i<m;i++)
	{
		ll temp;
		cin>>temp;
		mb.insert(pair<ll ,ll>(temp , 1));
	}
	it = mb.begin();
	for(ll i = 0;i<n;i++)
	{
		it = mb.find(a[i]);
		if(it != mb.end())
		{
			aa[i] = 1;
		}
		else
		{
			aa[i] = -1;
		}
		// cout<<aa[i]<<" "; 	
	}

	for(ll i = 0;i<n;i++)
	{
		// cout<<ii<<" "<<jj<<endl;
		incj();
		
		if(aa[i] == 1)
		  minsert(a[i]);

		if(uu >= k)
		{
			inci(k);
			ans = min(ans , (jj - ii + 1));
		}

	}

	if(ans == INT_MAX)
		cout<<-1<<endl;
	else
		cout<<ans-1<<endl;

}