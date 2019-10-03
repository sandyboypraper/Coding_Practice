#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	ll t;
	cin>>t;

	while(t--)
	{
			string a,b;
			cin>>a>>b;

			ll mapp[27];
			memset(mapp , 0 , sizeof(mapp));
			
			for(ll i = 0;i<b.length();i++)
			{
				mapp[b[i] - 'a']++;
			}

			string ba = "";
			ll flag = 0;
			
			for(ll i = 0;i<a.length();i++)
			{
				if(mapp[a[i] - 'a'] > 0)
				{
					ba += a[i];
					mapp[a[i] - 'a']--;
				}
				else
				{
					cout<<"Impossible"<<endl;
					flag = 1;
					break;
				}
			}

			if(flag == 1)
				continue;

			string bbachi = "";
			for(ll i = 0;i<26;i++)
			{
				while(mapp[i]>0)
				{
					bbachi += (i + 'a');
					mapp[i]--;
				}
			}

			string ans = "";

			for(ll i = 0;i<bbachi.length();i++)
			{
				if(ba[0] < bbachi[i])
				{
					ans = bbachi.substr(0 , i) + ba + bbachi.substr(i);
					break;
				}
			}

			if(ans == "")
				ans = bbachi + ba;


			cout<<ans<<endl;

	}
}				