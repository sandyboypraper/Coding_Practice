#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve(){
    ll n;cin>>n;
    string b;cin>>b;
    char res = '0';
    string ans = "";
    for(int i = 0;i<b.length();i++)
    {
        if(res == '0')
            {
                if(b[i] == '0')
                {
                    ans += '1';
                    res = '1';
                }
                else{
                    ans += '1';
                    res = '2';
                } 
            }
        else if(res == '1')
            {
                 if(b[i] == '0')
                {
                    ans += '0';
                    res = '0';
                }
                else{
                    ans += '1';
                    res = '2';
                } 
            }
        else{
             if(b[i] == '0')
                {
                    ans += '1';
                    res = '1';
                }
                else{
                    ans += '0';
                    res = '1';
                } 
        }
    }

    cout<<ans<<endl;
}

int main()
{
    ll t;cin>>t;
    while(t--)solve();
}