#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll mod = 1000000007;

ll nc4(ll n)
{

    if(n < 4)
        return 0;

    if(n==4)
        return 1;

    ll a = n,b = n-1,c = n-2,d = n-3;

    ll inv = 41666667;    

   ll k = ((a*b)%mod * (c*d)%mod)%mod;

   return (k * inv)%mod;
}

ll four(ll n)
{
    return ((n*n)%mod * (n*n)%mod)%mod;
}

int main(){
    ll t;
    
    cin>>t;
    
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans = 0;
        
        for(ll i = 1;i<=n/4;i++)
        {
            ll countmultiples = n/i;
            ll choices = nc4(countmultiples);
            ans = (ans + (choices*four(i))%mod)%mod;

            cout<<"shuru "<<i<<" "<<countmultiples<<" "<<choices<<" "<<ans<<endl;
            
            for(ll j = 1 ; j <= sqrt(i) && j < i ; j++)
            {
                if(i%j == 0)
                {
                    ll a = i/j;
                    ll b = i/a;
                    
                    if(a != i)
                     {
                        ans  = (ans - (four(a)*choices)%mod)%mod;
                      }
                    if(b != i)
                    ans = (ans - (four(b)*choices)%mod)%mod;
                }
            }
            cout<<ans<<endl;
        }
        
        cout<<ans<<endl;
    }
}