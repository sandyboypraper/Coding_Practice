	#include<iostream>

using namespace std;

template <class X , class Y>
X big(X a, Y b)
{
	if(a>b)
		return (a);
	else
		return (b);
}

// class template
template <class X , class Y>
class mpair
{
	
public:
	X first;
	Y second;
	mpair(X a, Y b)
	{
		first = a;
		second = b;
	}
};

int main()
{
	int a,b;
	a = 3;
	b = 5;

	double aa = 2.3;
	double bb = 4.5;
	cout<<big(a , b);
	cout<<big(aa , b);

	mpair<int , int> p(3,4);
	cout<<p.first<<"   "<<p.second;
}