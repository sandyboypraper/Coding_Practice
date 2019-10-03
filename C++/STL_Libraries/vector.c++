#include<iostream>

using namespace std;

template<class X>
class mvector
{
private:
	X *A;
	int size;
	int mat;
public:
	mvector(int k)
	{
		A = (X *)malloc(k*sizeof(X));
		size = k;
		mat = 0;
	}

	mvector()
	{
		A = (X *)malloc(sizeof(X));
		size = 1;
		mat = 0;
	}

	void mpush_back(X a)
	{
		if(mat == size)
		{
			A = (X *)realloc(A , 2*size*sizeof(X));
			size = 2*size;
		}
		    *(A + mat + 1) = a;
		    mat++;
	}

	X mback()
	{
		return *(A + mat);
	}

	int msize()
	{
		return mat;
	}

	void mprint()
	{
		for(int i = 1;i<=mat;i++)
		{
			cout<<*(A + i)<<endl;
		}
	}

	int area()
	{
		cout<<size;
	}

};

int main()
{
	mvector<int> mv;
	int n;
	cin>>n;

	for(int i = 0;i<n;i++)
	{
		int a;
		cin>>a;
		mv.mpush_back(a);
	}

	mv.area();
}