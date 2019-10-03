#include<bits/stdc++.h>

using namespace std;

int score(int a , int b)
{
	if((a > 0 && b>0 ) || (a<0 && b<0) || (a == 0 && b == 0))
	{
		return 1;
	}
	else{
		return 0;
	}
}

string ans(int a)
{
	if(a>0)
		return "+";
	
	if(a<0)
		return "-";
	
	return "0";
}

int main()
{
	int x,y,z;

	cin>>x>>y>>z;

	int delta = x-y;

	if(score(x-y-z , x-y+z) == 0)
	{
		cout<<"?"<<endl;
	}
	else
		cout<<ans(x-y)<<endl;
}
