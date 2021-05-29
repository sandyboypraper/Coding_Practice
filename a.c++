#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int getPowerCouple2021(int friends_nodes, int friends_edges, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight) {
    map<int, unordered_set<int>> mp;

    for(int i = 0;i<friends_edges;i++)
    {
        mp[friends_weight[i]].insert(friends_from[i]);
        mp[friends_weight[i]].insert(friends_to[i]);
    }

    priority_queue<int> pair_with_max_interest;
    map<int , vector<pair<int,int>>> map_of_pairs;
    map<int, unordered_set<int>> :: iterator it = mp.begin();

    for(int i = 1;i<=friends_nodes;i++)
    {
        for(int j = i+1;j<=friends_nodes;j++)
        {
            int counts = 0;
            while(it != mp.end())
            {   
                unordered_set<int> temp = it -> second;
                if(temp.count(i) && temp.count(j))
                {
                    counts++;
                }
                it++;
            }

            it = mp.begin();

            map_of_pairs[counts].push_back({i , j});
            pair_with_max_interest.push(counts);
        }
    }

    vector<pair<int,int>> vec_of_pairs = map_of_pairs[pair_with_max_interest.top()];
    int maxi = 0;
    for(int i = 0;i<vec_of_pairs.size();i++){
        maxi = max(maxi, vec_of_pairs[i].first * vec_of_pairs[i].second);
    }

    return maxi;
}   

int main()
{
    vector<int> friends_from = {1,1,2,2};
    vector<int> friends_to = {3,3,4,4};
    vector<int> friends_weight = {1,2,1,2};
    cout<<getPowerCouple2021(4, 4, friends_from, friends_to, friends_weight);
}