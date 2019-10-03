#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	ll n,m;
	cin>>n>>m;

	//person , option
	ll arr[1004][6];
	memset(arr , 0 ,sizeof(arr));

	// person
	for(ll i = 0;i<n;i++)
	{
		string demo;
		cin>>demo;

		//question
		for(ll j = 0;j<demo.length();j++)
		{
			 arr[j][demo[j] - 'A']++;
		}
	}


	ll anss[1004];
	memset(anss , 0  ,sizeof(anss));

	for(ll i = 0;i<m;i++)
		cin>>anss[i];

	ll ans = 0;

	for(ll j = 0;j<m;j++)
	{
		ll maxi = arr[j][0];
		maxi = max(maxi , arr[j][1]);
		maxi = max(maxi , arr[j][2]);
		maxi = max(maxi , arr[j][3]);
		maxi = max(maxi , arr[j][4]);

		ans += (maxi*anss[j]);
	}

	cout<<ans<<endl;	

}