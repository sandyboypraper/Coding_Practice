#include<iostream>

using namespace std;

class Complex
{
private:
	int a,b;
public:
	Complex(int a , int b)
	{
		this->a = a;
		this->b = b;
	}

	void display()
	{
		cout<<a<<" "<<b<<endl;
	}
};

int main()
{
	Complex c1(2,5);
	c1.display();
}