#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int t;
int n;
int a[1000001];
int memo[2000001];
 
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cin >> t;
	while(t--)
	{
		memset(memo,0,sizeof memo);
		int res =0 ;
		cin >> n;
		for (int i=1;i<=n;i++)
		{
			cin >> a[i];
			memo[a[i]] += 1;
		}	
		for (int i=0;i<20;i++)
			for (int bitmask=0;bitmask<(1<<20);bitmask++)
				if ((1<<i) & bitmask)
					memo[bitmask] += memo[bitmask ^ (1<<i)];
		for (int i=1;i<=n;i++)
		{
			if (!a[i])
				res += n;
			else
			{
				int cur = (((1<<20) - 1) ^ (a[i]));
				res += memo[cur];	
			}
		}
		cout << res << '\n';
	}
}