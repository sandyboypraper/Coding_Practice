#include<iostream>

using namespace std;

struct edge
{
	int src,int des;
};

struct node
{
	int val;
	node * next;
}

class Graph
{
	node **A;
	int nodes;
public:
	node * addNode(int des , node * head)
	{
		node *newnode = (node *)malloc(sizeof(node));
		newnode->val = des;

		newnode->next = head;

		return newnode;
	}

	Graph(int nodes, edge edges[] , int noe)
	{
		this->nodes = nodes;

		A = new node*[nodes]();

		for(int i = 0;i<nodes;i++)
			A[i] = nullptr;

		for(int i = 0;i<noe;i++)
		{
			int src = edges[i].src;
			int des = edges[i].des;

			node * newnode = addNode(des , A[src]);
			A[src] = newnode;
		}
	}
};