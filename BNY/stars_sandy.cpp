#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll get_factorial[100009];
ll get_factorial_inversse[100009];

ll moduloExpo(ll no, ll power)
{
	ll ans = 1;
	while(power>0)
	{
		if(no % 2 == 1)ans = (ans * no)%MOD;
		no = (no*no)%MOD;
		power = power/2;
	}
	return ans;
}

ll moduloInverse(ll no)
{
	return moduloExpo(no , MOD-2);
}

void fillFactorialAndFactorialInverseArray()
{
	for(ll i = 1;i<=100000;i++)
	{
		get_factorial[i] = (get_factorial[i-1] * i)%MOD;
		get_factorial_inversse[i] = moduloInverse(get_factorial[i]);
	}
}

int main()
{
	ll t;
	cin>>t;

	get_factorial[0] = 1;
	get_factorial_inversse[0] = 1;
	fillFactorialAndFactorialInverseArray();

	while(t--)
	{
		ll n,k;cin>>n>>k;

		if(k == 1)
			cout<<0<<endl;
		else if(k>n)
			cout<<1<<endl;
		else
		{
			ll totalPossible = n;
			ll totalMayBeSame = 0;

			for(ll i = 1;i<k-1;i++)
			{
				totalPossible = (totalPossible + (((n*get_factorial[n-1])%MOD)*((get_factorial_inversse[i]*get_factorial_inversse[k-1-i])%MOD))%MOD)%MOD;
			}

			totalMayBeSame = totalPossible;
			cout<<totalPossible<<" "<<totalMayBeSame<<endl;
			// cout<<(((get_factorial[n]*get_factorial_inversse[k])%MOD)*get_factorial_inversse[n-k])%MOD<<endl;
			totalPossible = ( totalPossible + (((get_factorial[n]*get_factorial_inversse[k])%MOD)*get_factorial_inversse[n-k])%MOD)%MOD;
			
			ll ans = (totalMayBeSame * moduloInverse(totalPossible))%MOD;
			
			cout<<ans<<endl;
		}
	}
}