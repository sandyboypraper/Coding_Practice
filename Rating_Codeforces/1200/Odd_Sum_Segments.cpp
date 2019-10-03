#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
		ll q;
		cin>>q;

		while(q--)
		{
			ll n,k;
			cin>>n>>k;
			vector<ll> v(n);
			
			ll nodd = 0;

			for(ll i = 0;i<n;i++)
			{
				cin>>v[i];
				if(v[i]%2!=0)
					nodd++;
			}

			ll fact = k%2;
			if(nodd%2 != fact || nodd < k)
			{
				cout<<"NO"<<endl;
			}
			else
			{
				cout<<"YES"<<endl;
				for(ll i = 0;i<n;i++)
				{
					if(k == 1)
						break;
					if(v[i]%2 != 0)
						{
							cout<<(i+1)<<" ";
							k--;
						}
				}
				cout<<(n)<<endl;
			}

		}


}

