#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	cin>>n;

	int order = (n/2) + 1;

	cout<<order<<endl;

	int o = 1;
	for(int i = 1;i<=n;i++)
	{
		if(i%2 == 0)
		{
			cout<<o<<" "<<o+1<<endl;
			o++;
		}
		else
			cout<<o<<" "<<o<<endl;
	}
}
