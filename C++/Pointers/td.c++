#include<iostream>

using namespace std;

int main()
{
	int b[2][3] = {{1, 2, 3}, {2 ,4 ,5}};

	cout<<b[1][2]<<"    "<<*(*(b+1)+2)<<endl;


	int bb[1][2][3] = {{{1,2,3} , {2,3,4}}};

	cout<<bb[0][1][2]<<"   "<<*(*(*(bb)+1)+2)<<endl;
}