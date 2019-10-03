#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int cheack(string s)
{
	if(s.length() == 1)
		return 1;

	int countchar = 0;
	int arr[26] = {0};

	for(int i = 0;i<s.length();i++)
	{
		if(arr[s[i] - 'a'] == 0)
		{
			countchar++;
		}

		arr[s[i] - 'a']++;
		if(countchar > 2)
			return 0;
	}

	if(countchar == 1)
		return 1;

	for(int i = 0;i<s.length()-1;i++)
	{
		if(s[i] == s[i+1])
			return 0;
	}

	return 1;
	
} 


int main()
{
	ll n;
	cin>>n;
	vector<string> sv;

	int ans = 0;

	for(int i = 0;i<n;i++)
	{
		string s;
		cin>>s;
		sv.push_back(s);
		ans = ans + cheack(s);
	}

	cout<<ans;
}