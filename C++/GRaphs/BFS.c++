#include<bits/stdc++.h>

using namespace std;


class mqueue
{
	int *q;
	int mfront;
	int mrear;
	int msize;
	int mcapacity;

public:
	mqueue(int n)
	{
		mcapacity = n;
		q = new int[n];
		mfront = 0;
		mrear = -1;
		msize = 0;
	}

	int enqu(int no)
	{
		if(msize == mcapacity)
		{
			return 0;
		}

		mrear = (mrear+1)%mcapacity;
		q[mrear] = no;
		msize++;
		return 1;
	}

	int dequ()
	{
		if(msize == 0)
		{
			return -1;
		}

		if(msize == 1)
		{
			msize--;
			int tempp = mfront;
			mfront = 0;
			mrear = -1;
			return q[tempp];
		}

		int tempp =  q[mfront];
		mfront++;
		mfront = mfront%mcapacity;
		msize--;
		return tempp;
	}

	int front()
	{
		if(msize == 0)
			return -1;
		return q[mfront];
	}

	int empty()
	{
		if(msize <= 0)
			return 1;

		return 0;
	}
};


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

	void BFS(int src)
	{
		mqueue qq(2*N);
		qq.enqu(src);

		int visited[N+1];
		memset(visited , 0 , sizeof(visited));

		while(!qq.empty())
		{
			int f = qq.front();
			visited[f] = 1;
			cout<<f<<"  ";
			qq.dequ();

			node * init = G[f];
			while(init != nullptr)
			{
				if(!visited[init->val])
				{
					qq.enqu(init->val);
					visited[init->val] = 1;
				}

				init = init->next;
			}
		}
	}
};

int main()
{
	int n;
	int m;
	cin>>n>>m;

	Edge e[m];

	for(int i = 0;i<m;i++)
	{
		cin>>e[i].src>>e[i].des;
	}

	Graph G(n , e , m);
	G.printGraph();
	G.BFS(1);
}