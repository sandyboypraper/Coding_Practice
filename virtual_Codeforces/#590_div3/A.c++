#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll; 

#define fr(init , fin) for(int i = init;i<=fin;i++)
#define frD(init , fin) for(int i = fin;i>=init;i--)
#define exp(a , x) for(auto& a : x)

#define printmat(a , row , col) for(int i = 0;i<row;i++){for(int j = 0;j<col;j++)cout<<a[i][j]<<" ";cout<<endl;}

// 20/7 = 3 

void solve()
{
	ll n;
	cin>>n;
	ll arr[n+1];
	ll sum = 0;
	fr(1 , n){cin>>arr[i];sum += arr[i];}
	cout<<(sum + n - 1)/n<<endl;	
}

int main()
{
	ll q;
	cin>>q;
	fr(1 , q)solve();
}