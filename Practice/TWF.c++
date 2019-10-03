#include<bits/stdc++.h>

using namespace std;

float findcost(float X , float dist)
{
	    float k = ceil(X/5);
		k--;
		ans = (10 + 8*((k >= 0)?k:0))*dist;
		return ans
}

int main()
{
	float X,Y,Z;
	cin>>X>>Y>>Z;

	float ans = 0;

	float XY , YZ , XZ;

	if(Y==0 && Z==0)
	{
		ans = findcost(X , 3);
	}
	else if(X==0 && Z==0)
	{
		ans = findcost(Y , 2.5);
	}
	else if(Y==0 && X==0)
	{
		ans = findcost(Z , 2);
	}
	else if(X==0)
	{
		float A = findcost(Y , 2.5) + findcost(0 , 2) + findcost(Z , 2);
		float B = findcost(Y , 5) + findcost(Z , 2);
		ans = min(A , B);
		YZ = ans;
	}
	else if(Y == 0)
	{
		 ans = findcost(X , 3) + findcost(0 , 2) + findcost(Z , 2);
		 XZ = ans;
	}
	else if(Z == 0)
	{
		float A = findcost(X , 3) + findcost(0 , 2.5) + findcost(Y , 2.5);
		float B = findcost(X , 6.5) + findcost(Y , 2.5);
		ans = min(A , B);
		XY = ans;
	}
	else
	{
		float A = XY + findcost(0 , 2) + findcost(Z , 2);
		float B = XZ + findcost(0 , 2.5) + findcost(Y , 2.5);
		float C = YZ + findcost(0 , 3) + findcost(X , 3);
		ans = min(A , min(B , C));
	}

	cout<<ans;
}