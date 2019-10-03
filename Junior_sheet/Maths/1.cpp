// https://codeforces.com/contest/1/problem/A

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
	double n,m,a;
	cin>>n>>m>>a;

	n = ceil(n/a);
	m = ceil(m/a);

	ll ans = n*m;

	cout<<ans<<endl;
}