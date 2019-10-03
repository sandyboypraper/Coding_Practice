#include<bits/stdc++.h>
typedef long long i64;
using namespace std;
int const MOD = 1000000007;
long long const INF = 1e18;
#define PI 3.14159265358979323846

i64 Is_Magical(string s)
{
	// if string contain only one charater
	if(s.length() == 1)
		return 1;
	i64 setChar = 0;
	i64 mapp[26] = {0};

	// count the total no of unique Charater
	for(i64 i = 0;i<s.length();i++)
	{
		if(mapp[s[i] - 'a'] == 0)
		{
			setChar++;
		}

		mapp[s[i] - 'a']++;
		if(setChar > 2)
			return 0;
	}

	// if containe only one character
	if(setChar == 1)
		return 1;

	// for magical string should conatine only two unique character and
	// they must be come alternatively
	for(i64 i = 0;i<s.length()-1;i++)
	{
		char a = s[i];
		char b = s[i+1];
		if(a == b)
			return 0;
	}

	return 1;
	
} 

int main()
{
	i64 N;
	cin>>N;
	i64 ans = 0;
	for(i64 i = 0;i<N;i++){
		string temp;
		cin>>temp;
		ans = ans + Is_Magical(temp);
	}
	cout<<ans<<endl;
}

