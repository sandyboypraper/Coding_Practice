#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool isPosibble(multiset<int , greater<int>> arr, int maxiknown)
{
    if(arr.size() == 0)return true;
    int maxi = *(arr.begin());
    arr.erase(arr.begin());
    if(arr.find(maxiknown - maxi) != arr.end())
    {   
        auto itt = arr.lower_bound(maxiknown-maxi);
        arr.erase(itt);
        return isPosibble(arr , maxi);
    }else return false;
}

auto getAns(multiset<int , greater<int>> &arr)
{
    int maxi = *(arr.begin());
    cout<<"maxi in get ANS "<<maxi<<endl;
    arr.erase(arr.begin());
    auto itr = arr.begin();
    while(itr != arr.end())
    {
        int temp = *(itr);
        cout<<"TEMP "<<temp<<endl;
        arr.erase(itr);
        if(isPosibble(arr , maxi))
        {
           return true;
        }
        else
        {
            arr.insert(temp);
        }
        itr++;
    }
    return false;
}

void solve(){
    ll n;cin>>n;
    multiset <int , greater<int>> arr;
    for(int i = 0;i<2*n;i++){
        int temp;cin>>temp;
        arr.insert(temp);
    }

    cout<<getAns(arr)<<endl;
}

int main()
{
    ll t;cin>>t;
    while(t--)solve();
}