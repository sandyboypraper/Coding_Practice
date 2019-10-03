#include<stdio.h>
long long MOD = 1000000007;
long long Fact[100005], Fact_Inv[100005];

long long Expo(long long x , long long n)
{
	long long get = 1;
	while(n>0)
	{
		if(n&1)
		{
			get = (get * x)%MOD;
		}
		x = (x*x)%MOD;
		n /= 2;
	}
	return get;
}

int main()
{
	long long testcases;
	scanf("%lld",&testcases);
	long long i = 0;
	long long N = 0,K = 0;
	long long P = 0,Q = 0;
	long long ans = 0;
	Fact[0] = 1;
	Fact_Inv[0] = 1;
	for(i = 1;i<=100000;i++)
	{
		Fact[i] = (Fact[i-1]*i)%MOD;
		Fact_Inv[i] = Expo(Fact[i] , MOD - 2);
	}

	while(testcases--)
	{
		N = 0;
		K = 0;
		scanf("%lld",&N);
		scanf("%lld",&K);

		if(K == 1)
			printf("%d\n",0);
		else if(K > N)
			printf("%d\n", 1);
		else
		{
			P = 0;
			Q = N;

			for(i = 1;i<K-1;i++)
			{
				Q = (Q + (((N*Fact[N-1])%MOD)*((Fact_Inv[i]*Fact_Inv[K-1-i])%MOD))%MOD)%MOD;
			}

			P = Q;
			Q = (Q + (((Fact[N]*Fact_Inv[K])%MOD)*Fact_Inv[N-K])%MOD)%MOD;
		
			printf("%lld %lld\n",P,Q);
			ans = (P * Expo(Q , MOD-2))%MOD;
			printf("%lld\n" , ans);
		}
	}
}

