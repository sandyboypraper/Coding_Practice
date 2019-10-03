#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll calxy(ll x , ll y , ll p)
{
	ll res = 1;    
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
}

int main()
{
	ll h,ww;
	cin>>h>>ww;

	ll empty = 0;

	vector<ll> r(h),w(ww);

	ll arr[1003][1003];
	memset(arr , 0 , sizeof(arr));

	for(ll i = 0;i<h;i++)
	{
		ll a;
		cin>>a;
		r[i] = a;
		for(ll j = 0;j<a;j++)
		{
			arr[i][j] = 1;
		}
	}	

	for(ll i = 0;i<ww;i++)
	{
		ll a;
		cin>>a;
		w[i] = a;
		for(ll j = 0;j<a;j++)
		{
			arr[j][i] = 1;
		}
	}

	for(ll i = 0;i<h;i++)
	{
		ll temp = 0;
		for(ll j = 0;j<ww;j++)
		{
			if(arr[i][j] == 1)
			  {
			  	temp++;
			  }
			else
			   break;
		}
		if(temp != r[i])
		{
			cout<<0;
			return 0;
		}
	}

	for(ll i = 0;i<ww;i++)
	{
		ll temp = 0;
		for(ll j = 0;j<h;j++)
		{
			if(arr[j][i] == 1)
				{
					temp++;
				}
			else
				break;
		}
		if(temp != w[i])
		{
			cout<<0;
			return 0;
		}
	}

	// for(ll i = 0;i<h;i++)
	// 	cout<<r[i]<<"  ";

	// cout<<endl;

	// for(ll i = 0; i<ww;i++)
	// 	cout<<w[i]<<"  ";

	// cout<<endl;	

	for(ll i = 1;i<h;i++)
	{
		for(ll j = 1;j<ww;j++)
		{
			if(r[i] < j && w[j] < i)
			{
				// cout<<i<<" "<<j<<endl;
				empty++;
			}
		}
	}

	// cout<<empty<<endl;

	cout<<calxy(2 , empty , 1000000007);

}