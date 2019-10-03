#include<bits/stdc++.h>

// (x + y)    n
// n%(x + y - 1*t) == 0
//  ans = 1

// find the value of t

// 	if t == 0
// 		tehn ans = 0
// 	else s -= t;
// 			t -= t
// 			ans = min(s,t);
// 		

using namespace std;
typedef long long int ll;

int main()
{
	ll t;
	cin>>t;

	while(t--)
	{
		ll n,s,T;
		cin>>n>>s>>T;

		ll count = 0;

		while(n%(s+T - count) != 0)
			count++;

		if(count==0)
		{
			cout<<1<<endl;
			continue;
		}
		else
		{
			s -= count;
			T -= count;

			cout<<max(s,T)+1<<endl;	
		}
	}
}	