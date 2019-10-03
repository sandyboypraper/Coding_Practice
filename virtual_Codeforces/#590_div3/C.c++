#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll; 

#define fr(i ,init , fin) for(int i = (init);i<=(fin);i++)
#define frD(i ,init , fin) for(int i = (fin);i>=(init);i--)
#define exp(a , x) for(auto& a : x)
#define clr(a , b) memset(a , b , sizeof(a))

#define printmat(a , row , col) for(int i = 0;i<row;i++){for(int j = 0;j<col;j++)cout<<a[i][j]<<" ";cout<<endl;}

ll relmat[7][7];

string solve()
{
	ll n;
	cin>>n;
	string a,b;
	cin>>a>>b;

	dp[2][n+1];
	clr(dp , 0);
	dp[1][n] = 1;
	if(relmat[a[n-1] - '0'][b[n-1] - '0'])dp[0][n] = 1;
	frD(i , 1 , n-1)
	{
		
	}
}

int main()
{
	clr(relmat , 0);
	fr(i , 1, 2)fr(j , 1 , 2)relmat[i][j] = 1;
	fr(i , 3 , 6)fr(j , 3 , 6)relmat[i][j] = 1;
	printmat(relmat , 7 , 7);

	ll q;
	cin>>q;
	fr(i , 1 , q)cout<<solve()<<endl;
}