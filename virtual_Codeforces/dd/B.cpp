#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
int main()
{
	ll n;
	cin>>n;
 
	priority_queue <ll> q;
 
	for(ll i = 0;i< n;i++)
	{
		ll a;
		cin>>a;
 
		q.push(a);
	}
 
	int flag = 1;
 
	while(!q.empty())
	{
		ll a = q.top();q.pop();
 
		if(q.empty())
			{
				flag = 0;
				break;
			}
 
		ll b = q.top();q.pop();

		ll c;
		if(!q.empty())
			c = q.top();
		else
		{
			if(a != b)
				flag = 0;

			break;
		}

		ll fact = b-c;
 
		a -= fact;
		b -= fact;

		if(a != 0)
			q.push(a);
		if(b != 0)
			q.push(b);
 
	}
 
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}