#include<bits/stdc++.h>

using namespace std;

struct data{
	int val;
};

template<class X>
class Heap
{
	X * Tree;
	int N;
	int size;
public:
	int left(int i)
	{
		return 2*i;
	}

	int right(int i)
	{
		return 2*i+1;
	}

	int isLow(X a , X b)
	{
		return a.val < b.val;
	}

	int isHigh(X a, X b)
	{
		return a.val > b.val;
	}

	void swap(int a , int b)
	{
		X temp = Tree[a];
		Tree[a].val = Tree[b].val;
		Tree[b].val = temp.val;
	}

	int parent(int i)
	{
		return i/2;
	}

	int up(int low)
	{
		if(parent(low) == 0)
			return 0;

		if(isLow(Tree[parent(low)] , Tree[low]))
		{	
			swap(parent(low) , low);
			return 1;
		}

		return 0;
	}

	int down(int up)
	{
		if(up == size)
			return 0;

		int a = left(up);
		int b = right(up);

		if(isLow(Tree[up] , Tree[a]))
		{
			swap(up , a);
			return 1;
		}

		if(isLow(Tree[up] , Tree[b]))
		{
			swap(up , b);
			return 1;
		}

		return 0;

	}

	void addNode(int no)
	{
		Tree[++size].val = no;
		int p = parent(size);

		int up1 = p;
		int low1 = size;

		while(up(low1)){
			low1 = parent(low1);
		};	
	}

	Heap(X * Arr , int n)
	{
		N = n;
		size = 0;
		Tree = new X[n+1];
		for(int i = 0;i<n;i++)
		{
			addNode(Arr[i].val);
		}
	}

	void HeapSort()
	{
		if(size==0)
			return;
		cout<<Tree[1].val<<"  ";
		Tree[1].val = Tree[size].val;
		size--;
		int up1 = 1;
		if(!down(up1))
			return;	
		else
			HeapSort();
	}

};

int main()
{
	int n;
	cin>>n;

	data * Arr = (data *)malloc(n*sizeof(data));

	for(int i = 0;i<n;i++)
	{	
		cin>>Arr[i].val;
	}

	Heap <data> h(Arr , n);
	h.HeapSort();
}