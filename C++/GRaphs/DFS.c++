#include<bits/stdc++.h>

using namespace std;

int visited[10000];

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
		node * tempn = (node *)malloc(sizeof(node));
		tempn->val = dess;
		tempn->next = srcc;
		srcc = tempn;
		return srcc;
	}

	Graph(int n ,  Edge e[] , int m)
	{
		G = new node*[n+1];
		N = n;

		for(int i = 0;i<=n;i++)
			G[i] = nullptr;

		for(int i = 0;i<m;i++)
		{
			int src = e[i].src;
			int des = e[i].des;

			node * temp = addNode(G[src] , des);
			G[src] = temp;
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

	Graph G(n , e , m);
	memset(visited , 0 , sizeof(visited));	
	G.DFS(1);
}