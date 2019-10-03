#include<bits/stdc++.h>
typedef long long i64;
using namespace std;
int const MOD = 1000000007;
long long const INF = 1e18;
i64 Q = 0,P = 0;
#define PI 3.14159265358979323846
i64 Factorials[100005], Factorials_Inverse[100005];


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


// calculate p and q of the probability
void calc_p_and_q(i64 N, i64 K)
{
	Q = N;
	for(i64 i = 1;i<K-1;i++)
	{
		i64 Q_wala = (Factorials_Inverse[i]*Factorials_Inverse[K-1-i])%MOD;
		Q = (Q + (((N*Factorials[N-1])%MOD)*Q_wala)%MOD)%MOD;
	}

	P = Q;
	i64 Q_wala_1 = (Factorials[N]*Factorials_Inverse[K])%MOD;
	Q = (Q + (Q_wala_1*Factorials_Inverse[N-K])%MOD)%MOD;
}


int main()
{
	// input no of test cases
	i64 T;
	cin>>T;

	// filling out the factorials and there inverse
	Factorials[0] = 1;
	Factorials_Inverse[0] = 1;
	for(i64 i = 1;i<=100000;i++)
	{
		Factorials[i] = (Factorials[i-1]*i)%MOD;
		Factorials_Inverse[i] = modulerExpo(Factorials[i] , MOD-2);
	}

	// running test cases
	while(T--)
	{
		// input N and K
		i64 N,K;
		cin>>N>>K;

		// solution easy peasy
		if(K == 1)
			cout<<0<<endl;
		else if(K>N)
			cout<<1<<endl;
		else
		{
			P = 0;
			Q = 0;
			calc_p_and_q(N , K);
			cout<<P<<" "<<Q<<endl;
			i64 ans = (P * modulerExpo(Q , MOD - 2))%MOD;
			cout<<ans<<endl;
		}
	}

}