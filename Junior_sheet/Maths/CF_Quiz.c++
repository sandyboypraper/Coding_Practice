#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vll; 

#define fr(i ,init , fin) for(int i = init;i<=fin;i++)
#define frD(i ,init , fin) for(int i = fin;i>=init;i--)
#define exp(a , x) for(auto& a : x)
#define clr(a , b) memset(a , b , sizeof(a))

#define printmat(a , row , col) for(int i = 0;i<row;i++){for(int j = 0;j<col;j++)cout<<a[i][j]<<" ";cout<<endl;}



template<class X>
class IntMod{
public:
	X n;
	static const int INVERSE_CACHE_SIZE = (1 << 20);	
	static X MOD;
	IntMod(X d){n = (d >= 0 ? d%MOD : d%MOD + MOD);}
	IntMod(){n = 0;}

	//return object
	static IntMod build(X n) { IntMod r; r.n = n; return r; }

	IntMod operator-() const { return build(n == 0 ? 0 : MOD - n); }
	IntMod& operator+=(IntMod a) { n = (n >= MOD - a.n ? n - MOD + a.n : n + a.n); return *this; }
	IntMod& operator-=(IntMod a) { n = (n >= a.n) ? n - a.n : n - a.n + MOD; return *this; }
	IntMod& operator*=(IntMod a) { *this = *this * a; return *this; }
	IntMod& operator/=(IntMod a) { *this = *this / a; return *this; }

	static X inverse_cache[INVERSE_CACHE_SIZE];
	static bool inverse_cache_ready;
	friend IntMod inverse(IntMod n){return build(inverse_internal(n.n));}
	static X inverse_internal(X n)
	{
		if (!inverse_cache_ready) 
		{
			inverse_cache_ready=true;
			inverse_cache[0] = 0;
			inverse_cache[1] = 1;
			for (int n = 2; n < INVERSE_CACHE_SIZE; ++n) inverse_cache[n] = (MOD - (X)((long long)inverse_cache[MOD % n] * (MOD / n) % MOD));
		}
		return n < INVERSE_CACHE_SIZE ? inverse_cache[n] : MOD - (X)((long long)inverse_internal(MOD % n) * (MOD / n) % MOD);
	}

	friend bool operator==(IntMod a , IntMod b){return a.n == b.n;}
	friend bool operator>(IntMod a, IntMod b){return a.n>b.n;}
	friend bool operator<(IntMod a , IntMod b){return a.n<b.n;}
	friend bool operator>=(IntMod a , IntMod b){return a.n>=b.n;}
	friend bool operator<=(IntMod a , IntMod b){return a.n<=b.n;}
	friend bool operator!=(IntMod a , IntMod b){return a.n != b.n;}
	friend IntMod operator+(IntMod a , IntMod b){return build(a.n >= MOD - b.n ? a.n - MOD + b.n : a.n + b.n); }
	friend IntMod operator-(IntMod a , IntMod b){return build(a.n >= b.n ? a.n - b.n : a.n - b.n + MOD); }
	friend IntMod operator*(IntMod a , IntMod b){return build(static_cast<X>(static_cast<ll>(a.n)*b.n % MOD));}
	friend IntMod operator/(IntMod a , IntMod b){return a*inverse(b);}
	friend IntMod operator%(IntMod a , IntMod b){return a.n%b.n;}
	friend IntMod pow(IntMod p , long long e)
	{
		if (e <= 0) return IntMod(1);
		IntMod r = IntMod(1);
		while (1) { if (e & 1) r *= p; e /= 2; if (e) p = p * p; else break; }
		return r;
	}

	friend istream& operator>>(istream &stream, IntMod &a) { stream >> a.n; return stream; }
	friend ostream& operator<<(ostream &stream, const IntMod &a) { stream << a.n; return stream; }

};

template<typename X> X IntMod<X>::inverse_cache[INVERSE_CACHE_SIZE];
template<typename X> bool IntMod<X>::inverse_cache_ready;




template<class X> X IntMod<X>::MOD = 1000000009;

using Int = IntMod<ll>;

int main()	
{
	ll n,m,k;
	cin>>n>>m>>k;

	// cout<<pow(Int(n) s, (ll)m)<<endl;
	ll score = n/k + n%k;
	ll counter = (k-1)*(n/k) + n%k;


	if(counter >= m)
	{
		cout<<m<<endl;
		return 0;
	}

	Int Bache = Int(m) - Int(counter);	
	// cout<<Bache<<" "<<score<<endl;
	Int Score = Int(k)*(pow(Int(2) , (ll)(m - counter + 1)) - Bache - Int(2)) + Int(m);
	// score = (score + Bache + (k*((Bache*(Bache + 1))/2)%MOD)%MOD)%MOD;
	cout<<Score<<endl;
}