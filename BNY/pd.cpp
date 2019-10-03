#include<bits/stdc++.h>

using namespace std;

int main()
{
	string date;
	cin>>date;

	int a = date[0] - '0';
	int b = date[1] - '0';
	int c = date[3] - '0';
	int d = date[4] - '0';

	int init = a*10 + b;

	if(d>5)
	{
		if(d == 6 && c == 0)
		{
			a = 6;
			b = 0;
			cout<<a<<b<<":"<<c<<d;
			return 0;
		}
		c++;
		d = 0;
		a = d;
		b = c;
		cout<<a<<b<<":"<<c<<d;
		return 0;
	}
	else
	{
		a = d;
		b = c;
		int fin = a*10 + b;

		if(fin < init)
		{
			if(d == 5)
			{
				c++;
				d = 0;
			}
			else if(c*10 + d == 30)
			{
				c = 0;
				d = 1;
				a = d;
				b = c;
				cout<<a<<b<<":"<<c<<d;
				return 0;
			}
			else
			{
				d++;
			}

			a = d;
			b = c;

			cout<<a<<b<<":"<<c<<d;
			return 0;
		}

		cout<<a<<b<<":"<<c<<d;
	}
}