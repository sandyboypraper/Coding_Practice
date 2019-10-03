#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	int limit = 4000000;
	int a = 1;
	int b = 2;
	ll ans = 2;
	
	int temp = a+b;

	while(temp < limit)
	{
		temp = a+b;
		if(temp%2 == 0)
			ans += temp;

		a = b;
		b = temp;

		cout<<temp<<" ";
	}

	cout<<temp;
}