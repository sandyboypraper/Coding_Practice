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


int main()
{
	ll n = 0;
	cin>>n;
	fr(0 , n-1)cout<<i,cout<<endl;
	frD(0 , n-1)cout<<i,cout<<endl;	
	vll v;
	ll t;
	cin>>t;
	fr(0 , t-1){ll temp = 0;cin>>temp;v.push_back(temp);}
	exp(a , v)cout<<a,cout<<endl;
	int arr[10][10];
	memset(arr , 0 , sizeof(arr));
	printmat(arr , 10 , 10);
}