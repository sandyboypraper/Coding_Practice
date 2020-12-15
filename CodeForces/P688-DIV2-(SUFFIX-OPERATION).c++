//there is no point for operation o1 because after that all the relative differences
// are same so operation started with 1 have no point

//so minimum steps for making whole array with single value is sum(abs(ai - a(i-1))) 
// means we have to make all numbers equal to first number

// so now just remove the maximum abs(ai - a(i-1))
// thats all :)

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    ll n;cin>>n;
    vector<ll> vec(n);
    for(ll i = 0;i<n;i++)cin>>vec[i];

    ll x = 0;
    for(ll i = 1;i<n;i++)x += abs(vec[i] - vec[i-1]);

    ll y = 0;
    if(n >= 2)
       y = abs(vec[1] - vec[0]);

    if(n >= 2)
       y = max(y , (ll)abs(vec[n-1] - vec[n-2]));

    for(ll i = 1;i<n-1;i++)
        y = max(y , abs(vec[i] - vec[i-1]) + abs(vec[i+1] - vec[i]) - abs(vec[i+1] - vec[i-1]));

    cout<<x-y<<endl;
}

int main()
{
    int t;cin>>t;
    while(t--)solve();
}