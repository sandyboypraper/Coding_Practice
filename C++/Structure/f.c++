#include<iostream>
#include<conio>
using namespace std;

struct book
{
	int bookid;
	char title[20];
	float price;
};

int main()
{
	// struct book b1; must is c
	book b1 = {100 , "sandyboyraper" , 200.9};
	book b2;
	b2.bookid = 101;
	strcpy(b2.title , "ss");
	b2.price = 300.0;

	book b3;
	b3 = b2;
}