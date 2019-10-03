#include<iostream>

using namespace std;

void printt()
{
	static int x = 0;
	cout<<x;
}

int main()
{
	printt();
	cout<<x<<endl;	
}