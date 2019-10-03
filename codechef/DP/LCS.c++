#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll dp[1000][1000];

ll leng(string a,string b,ll n,ll m)
{
	ll count = 0;

    if(n == 0 || m == 0)
	{
		if(a[n]==b[m])
			return 1;
		else
			return 0;	
	}

	cout<<n<<" "<<m<<endl;

	if(a[n-1] == b[m-1])
	{
		count++;
        count += leng(a,b,n-1,m-1);
	}
	else
	{
		count += max(leng(a,b,n-1,m), leng(a,b,n,m-1));
	}

	return count;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		memset(dp,-1,sizeof(dp));
		cout<<leng(a,b,a.length(),b.length())<<endl;
	}
}