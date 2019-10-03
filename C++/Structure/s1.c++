#include<iostream>

using namespace std;

struct book{
private:
	int bookid;

public:
	void input()
	{
		cin>>bookid;
	}

	void display()
	{
		cout<<bookid;
	}
};	

int main()
{
	book b1;
	b1.input();
	b1.display();
}