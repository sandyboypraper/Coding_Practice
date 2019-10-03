#include<iostream>

using namespace std;

struct node
{
	int val;
	node * next;
};

struct Edge
{
	int src;
	int des;
};

class Graph
{
	node **G;
	int N;
public:
	node * addNode(node * srcc , int dess)
	{
		// node tempn;
		// tempn.val = dess;

		// tempn.next = srcc;
		// srcc = &tempn;

		// return srcc;

		// or

		node * tempn = (node *)malloc(sizeof(node));
		tempn->val = dess;
		tempn->next = srcc;
		srcc = tempn;
		return srcc;
	}

	Graph(int n, Edge e[] , int noofedges)
	{
		N = n;
		G = new node*[N+1];

		for(int i = 0;i<n;i++)
			G[i] = nullptr;

		for(int i = 0;i<noofedges;i++)
		{
			int src = e[i].src;
			int des = e[i].des;

			node * temp = addNode(G[src] , des);
			G[src] = temp;
		}
	}

	void printGraph()
	{
		for(int i = 1;i<=N;i++)
		{
			node * init = G[i];

			cout<<"for "<<i<<endl;

			while(init != nullptr)
			{
				cout<<init->val<<"   ";
				init = init->next;
			}

			cout<<endl;
		}
	}
};

int main()
{
	int n,m;
	cin>>n>>m;

	Edge e[m];

	for(int i = 0;i<m;i++)
	{
		cin>>e[i].src>>e[i].des;
	}	

	Graph GG(n , e , m);
	GG.printGraph();

}