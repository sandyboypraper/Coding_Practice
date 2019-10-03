#include<iostream>
using namespace std;

class Complex
{
private:
	int a,b;
public:
	void setData(int x,int y)
	{
		a=x;b=y;
	}

	void showData()
	{
		cout<<a<<"  "<<b<<endl;
	}

	Complex operator +(Complex c)
	{
		Complex temp;
		temp.a = a+c.a;
		temp.b = b+c.b;
		return temp;
	}
};


int main()
{
	Complex c1,c2,c3;

	c1.setData(1,2);
	c2.setData(2,4);
	c3 = c1 + c2;
	c3.showData();
}