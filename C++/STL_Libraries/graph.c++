#include<iostream>

using namespace std;


template <class X , class Y>
class mpair
{
public:
	X first;
	Y second;

	mpair(X a , Y b)
	{
		first = a;
		second = b;
	}
};


template<class X, class Y>
mpair<X , Y> makep(X a , Y b)
{
	mpair<X , Y> temp(a, b);
	return temp;	
}


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
		    *(A + mat) = a;
		    mat++;
	}

	X pos(int po)
	{
		return *(A + po);
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
		for(int i = 0;i<mat;i++)
		{
			cout<<*(A + i)<<endl;
		}
	}

	int area()
	{
		cout<<size;
	}

};

mvector<mvector<mpair<int , int>>> Adjlist(20);

int main()
{
	int n;
	cin>>n;

	int m;
	cin>>m;

	for(int i = 0;i<m;i++)
	{
		int a = 0;
		int b = 0;
		int w = 0;
		cin>>a>>b>>w;

		Adjlist.pos(a).mpush_back(makep(b,w));
	}

	cout<<Adjlist.pos(2).pos(0).first<<endl;

	// for(int i = 1;i<=n;i++)
	// {
	// 	mvector<mpair<int , int>> temmp = Adjlist.pos(i);
	// 	cout<<(int)temmp.msize()<<endl;

	// 	cout<<Adjlist.pos()

	// 	for(int j = 0;j<(int)Adjlist.pos(i).msize();j++)
	// 	{
	// 		mpair<int,int> mpp = Adjlist.pos(i).pos(j);
	// 		cout<<(i)<<"--->"<<mpp.first<<"++++"<<mpp.second<<endl;
	// 	}
	// }
}	