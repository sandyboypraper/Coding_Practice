#include<bits/stdc++.h>

using namespace std;

int ssum(int n)
{
	int sum = 0;
	int num = n;
	while (num != 0)
    {
        sum = sum + num % 10;
        num = num / 10;
    }
    return sum;
}

int cheacknext(int n)
{
	int summ = ssum(n);

	while(summ % 4 != 0)
	{
		summ = ssum(++n);
	}

	return n;
}

int main()
{
	int a;
	cin>>a;

	
    cout<<cheacknext(a);

}