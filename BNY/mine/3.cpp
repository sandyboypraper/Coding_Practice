#include<bits/stdc++.h>
typedef long long i64;
using namespace std;
int const MOD = 1000000007;
long long const INF = 1e18;
#define PI 3.14159265358979323846
i64 Factorials[10000009], Factorials_Inverse[109];

//For moduler Inverse using power of MOD-2
i64 modulerExpo(i64 x, i64 y) 
{ 
    i64 po = 1;
    x = x % MOD; 
    while (y > 0) 
    { 
        if (y & 1) 
            po = (po*x) % MOD; 
        y = y>>1;
        x = (x*x) % MOD;   
    } 
    return po; 
} 

int main()
{
	// filling out the factorials and there inverse
	Factorials[0] = 1;
	Factorials_Inverse[0] = 1;
	for(i64 i = 1;i<=10000005;i++)
	{
		Factorials[i] = (Factorials[i-1]*i)%MOD;
	}
	for(i64 i = 1;i<101;i++)
	{
		Factorials_Inverse[i] = modulerExpo(Factorials[i] , MOD-2);
	}

	i64 K;
	cin>>K;

	i64 numbers[K];
	i64 weight = 0;

	for(i64 i = 0;i<K;i++)
	{
		cin>>numbers[i];
		weight += (numbers[i]-1);
	}

	i64 solution = Factorials[weight];

	for(i64 i = 0;i<K;i++)
	{
		if(numbers[i]!=1)
		{
			solution = ((solution*Factorials_Inverse[numbers[i]-1])%MOD)%MOD;
		}
	}

	cout<<solution;
}