#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll; 

#define fr(i ,init , fin) for(int i = init;i<=fin;i++)
#define frD(i ,init , fin) for(int i = fin;i>=init;i--)
#define exp(a , x) for(auto& a : x)
#define clr(a , b) memset(a , b , sizeof(a))

#define printmat(a , row , col) for(int i = 0;i<row;i++){for(int j = 0;j<col;j++)cout<<a[i][j]<<" ";cout<<endl;}

string solve()
{
	ll n;
	ll arr[10];
	fr(i , 1, n)
	{
		string s;
		cin>>s;
		fr(j , 0 , s.length())
		{
			arr[s[j] - '0']++:
		}
	}

	string ans = "";

	frD(i , 0 , 9)
	{
		fr(j , 0 , arr[i])ans += (i + '0');
	}

	return ans;
}

int main()
{
	ll q;
	cin>>q;
	cout<<solve()<<endl;
}