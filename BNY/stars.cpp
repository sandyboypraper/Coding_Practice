#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll fact[100005] , fact_inv[100005];

ll Mod = 1000000007;	


ll modinv(ll x,ll n)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%Mod;
        x=(x*x)%Mod;
        n=n/2;
    }
    return result;
}

ll inv(ll n)
{
	return modinv(n,Mod-2);
}

void fillfactnfact_inv()
{
	for(ll i = 1;i<=100000;i++)
	{
		fact[i] = (fact[i-1] * i)%Mod;
		fact_inv[i] = inv(fact[i]); 
	}
}


ll total = 0,totalup = 0;

void solve(ll n,ll k)
{
	total = n;
	
	for(ll i = 1;i<k-1;i++)
	{
		total = (total + (((n*fact[n-1])%Mod)*((fact_inv[i]*fact_inv[k-1-i])%Mod))%Mod)%Mod;
	}

	totalup = total;

	total = (total + (((fact[n]*fact_inv[k])%Mod)*fact_inv[n-k])%Mod)%Mod;
}

int main()
{
	ll t;
	cin>>t;

	fact[0] = 1;
	fact_inv[0] = 1;
	fillfactnfact_inv();

	while(t--)
	{
		ll n,k;
		cin>>n>>k;

		if(k == 1)
			cout<<0<<endl;
		else if(k>n)
			cout<<1<<endl;
		else
		{
			total = 0;
			totalup = 0;

			solve(n , k);
			cout<<total<<" "<<totalup<<endl;
			ll ans = (totalup * inv(total))%Mod;
			cout<<ans<<endl;
		}
	}
}