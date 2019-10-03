#include<iostream>

using namespace std;

int main()
{
	// int a = 5;
	// int *p = &a;

	// cout<<p<<endl;
	// cout<<*p<<endl;


	cout<<"+++++++++++++++++================++++++++++++"<<endl<<endl;


	// pointers to pointers

	int x = 5;
	int *p;
	p = &x;

	int **pp;
	pp = &p;

	cout<<**pp<<endl;
}