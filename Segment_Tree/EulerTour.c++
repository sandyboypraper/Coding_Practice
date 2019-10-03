#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e5;
const ll LIM = 1e6 + 5;

ll t[5*N];

ll n;
vector<vector<ll>> Adjlist(N);
vector<ll> Nodes(N+5);
vector<ll> Isgoodarr(N+5);
vector<ll> visited(N+5);
vector<ll> Route;
vector<ll> StartTime(N+1);
vector<ll> EndTime(N+1);
vector<ll> IsGood(LIM);

// int Isgood(ll no)
// {
// 	ll result = 0; 
  
//     for (ll i=2; i<=sqrt(no); i++) 
//     { 
//         if (no%i==0) 
//         { 
//             if (i==(no/i)) 
//                 result += i; 
//             else
//                 result += (i + no/i); 
//         } 
//     } 
//     result++;
    
//     result+=no;
    
//       if(result % 3 == 0)
// 		return 1;
		
// 		return 0;
// }

void findDivisors(ll n) 
{ 
  
    for (ll i = 1; i <= n; i++) { 
  
        for (ll j = 1; j * i <= n; j++) 
            IsGood[i * j] += i; 
            
    } 
    
    
    for(ll i = 1;i<=n;i++)
     {
         if(IsGood[i]%3 == 0)
          IsGood[i] = 1;
          else
          IsGood[i] = 0;
     }
} 

void makeRoute(ll u)
{
	visited[u] = 1;
	Route.push_back(u);
	for(ll i = 0;i<Adjlist[u].size();i++)
	{
		ll v = Adjlist[u][i];
		if(visited[v] == 0)
		{
			makeRoute(v);
		}
	}
	Route.push_back(u);
}

void makeTimeLine()
{
	for(ll i = 0;i<Route.size();i++)
	{
		if(StartTime[Route[i]] == 0)
			StartTime[Route[i]] = i+1;
		else
			EndTime[Route[i]] = i+1;
	}
}

void makeTree()
{
	for(ll i = 2*n-1;i>0;i--)
		t[i] = t[i<<1] + t[i<<1 | 1];
}

void update(ll ind , ll value)
{
	ll n = Route.size();
	ind--;
   for(t[ind+=n] = value ; ind > 1 ; ind >>= 1)t[ind>>1] = t[ind] + t[ind^1];
}


ll query(ll l , ll r)
{
  ll n = Route.size();	
  ll res = 0;
  for (l += n, r +=	 n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main()
{
	ll q;
	cin>>n>>q;
	
	findDivisors(1000002);

	for(ll i = 0;i<n-1;i++)
	{
		ll a,b;
		cin>>a>>b;
		Adjlist[a].push_back(b);
		Adjlist[b].push_back(a);
	}

	for(ll i = 0;i<n;i++)
		cin>>Nodes[i+1];

	for(ll i = 1;i<=n;i++)
		Isgoodarr[i] = IsGood[Nodes[i]];

	makeRoute(1);


	for(ll i = 0;i<Route.size();i++)
	{
		t[2*n+i] = Isgoodarr[Route[i]];
	}

	makeTimeLine();

	makeTree();

	while(q--)
	{
		ll t;
		cin>>t;

		if(t == 1)
		{
			ll x,y;
			cin>>x>>y;
			update(StartTime[x] , IsGood[y]);
			update(EndTime[x] , IsGood[y]);
		}
		else	
		{
			ll x;
			cin>>x;
			cout<<query(StartTime[x]-1 , EndTime[x])/2<<endl;
		}
	}
}