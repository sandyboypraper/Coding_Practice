#include<iostream>

using namespace std;


template <class X , class Y>
class mpair
{
public:
	X first;
	Y second;

	mpair(X a , Y b)
	{
		first = a;
		second = b;
	}
};

int main()
{
	pair<int , string> p(1 , "sss");

	cout<<p.first<<"   "<<p.second<<endl;
}