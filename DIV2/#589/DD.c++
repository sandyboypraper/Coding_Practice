#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll cheack(ll a)
{
	ll arr[10];
	memset(arr , 0  ,sizeof(arr));

	ll temp = 0;

	while(a>0)
	{

		temp = a%10;

		if(arr[temp] == 0)
			arr[temp] = 1;
		else
			return 0;

		a /= 10;

	}

	return 1;
}

int main()
{
	ll a,b;
	cin>>a>>b;

	for(ll i = a;i<=b;i++)
	{
		if(cheack(i))
		{
			cout<<i;
			return 0;
		}
	}

	cout<<-1;

}