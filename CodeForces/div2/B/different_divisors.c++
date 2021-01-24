#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

vector<int> primeNumbers;

bool isPrime(int n)//O(logn)
{
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int findNextPrime(int n)//O(nextPrime - n)logn
{
    int nextPrime = n;
    bool found = isPrime(nextPrime);

    while (!found)
    {
        nextPrime++;
        if (isPrime(nextPrime))
            found = true;
    }

    return nextPrime;
}

void fillPrimeNumbers(){
    primeNumbers.push_back(1);
    while(primeNumbers.back() < 100000)
    {
        primeNumbers.push_back(findNextPrime(primeNumbers.back() + 1));
        // cout<<primeNumbers.back()<<"  ";
    }
}


void solve(){
    ll d;cin>>d;
    ll nextPrime = primeNumbers[upper_bound(primeNumbers.begin() , primeNumbers.end() , d) - primeNumbers.begin()];
    // cout<<"first prime"<<nextPrime<<endl;
    ll nextPrime1 = primeNumbers[upper_bound(primeNumbers.begin() , primeNumbers.end() , nextPrime) - primeNumbers.begin()];
    // cout<<"second Prime"<<nextPrime1<<endl;
    while(nextPrime1 - nextPrime < d)
    {
        // cout<<nextPrime1-nextPrime<<endl;
        nextPrime1 = primeNumbers[upper_bound(primeNumbers.begin() , primeNumbers.end() , nextPrime1) - primeNumbers.begin()];
    }
    // cout<<"final second prime"<<nextPrime1<<endl;
    cout<<nextPrime*nextPrime1<<endl;
}

int main()
{
    fillPrimeNumbers();
    // cout<<"ok go"<<endl;
    ll t;cin>>t;
    while(t--)solve();
}