#include<iostream>

using namespace std;

// struct Complex
// {
// private:
// 	int a,b;
// public:
// 	void set_data(int x, int y)
// 	{
// 		a = x;
// 		b = y;
// 	}

// 	void show_data()
// 	{
// 		cout<<a<<" "<<b<<endl;
// 	}
// };

class Complex{
	 // int a,b;
	// or
private:
	int a,b;
public:
	void set_data(int x, int y)
	{
		a = x;
		b = y;
	}

	void show_data()
	{
		cout<<a<<" "<<b<<endl;
	}
}

int main()
{
	// Complex c1;
	// c1.set_data(3,4);
	// c1.show_data();

	//now the declaration is called as objects;
	Complex c1;
	c1.set_data();
	c1.show_data();
}