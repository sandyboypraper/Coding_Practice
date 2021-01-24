#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool isPosibble(multiset<int , greater<int>> &arr, int maxiknown)
{
    int maxi = *(arr.begin());
    arr.erase(arr.begin());
    if(arr.find(maxiknown - maxi) != arr.end())
    {   
        
    }else return false;
}

auto isPosibble(multiset<int , greater<int>> &arr , int maxiKnown = -1)
{
    vector<pair<int , int>> ans;
    int maxi = *(arr.begin());
    arr.erase(arr.begin());
    
    if(arr.find(maxiKnown - maxi) == arr.end() && maxiKnown != -1)return false;
    if(arr.find(maxiKnown - maxi) != arr.end() && maxiKnown != -1)return true;

    for(auto itr = arr.begin();itr != arr.end();itr++)
    {
        int temp = *(itr);
        arr.erase(itr);
        if(isPosibble(arr , maxi))
        {
            ans.push_back({maxi , temp});
        }
        else
        {

        }
    }
}

void solve(){
    ll n;cin>>n;
    multiset <int , greater<int>> arr;
    for(int i = 0;i<2*n;i++){
        int temp;cin>>temp;
        arr.insert(temp);
    }

    vector<pair<int , int>> ans = isPosibble(arr , -1);
}

int main()
{
    ll t;cin>>t;
    while(t--)solve();
}