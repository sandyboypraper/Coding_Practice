#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

class MyStack{
    private:
        stack<int> s;
        int minEle;

    public:
        void push(int el){
            s.push(el);
        }

        int top(){
            return s.top();
        }

        int findMin(){
            return minEle;
        }
};

int main(){
    MyStack ms;
}