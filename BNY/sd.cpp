#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
  string s;
  cin>>s;
  int l=s.length();
  vector<char>a;
  vector<int>b;
  int cou=1;
  lli fact[1000001];
  for(lli i=0;i<1000001;i++)
  {
  	if(i==0||i==1)
  		fact[i]=1;
  	else
  	{
  		fact[i]=fact[i-1]+i;
  	}
  }

  for(int i=0;i<s.length();i++)
  { 
  	if(i==l)
  	{
  	a.push_back(s[l-1]);
  	b.push_back(cou);
  	}
  	if(s[i]==s[i+1])
  	{
  		cou++;
  	}
  	else
  	{
     a.push_back(s[i]);
     b.push_back(cou);
     cou=1;
  	}
  }
  // for(lli i=0;i<b.size();	i++)
  // {
  // 	cout<<a[i]<<" ";
  // }
  // cout<<endl;	
  lli ans=l;
  for(lli i=1;a.size()>=3&&i<(a.size()-1);i++)
  {
  	if(b[i]==1&&a[i-1]==a[i+1]) ans=ans+min(b[i-1],b[i+1]);
  }
//cout<<ans<<endl;
  for(lli i=0;i<b.size();i++)
  {if(b[i]!=1)
  	ans=ans+fact[b[i]-1];
  }
  cout<<ans<<endl;
}