#include<bits/stdc++.h>

using namespace std;

int **dp, n , m;

int bfs(int i , int j , vector<vector<int>>& matrix)
{
    if(dp[i][j] != INT_MIN)return dp[i][j];

    int ans = 0;

    if(i + 1 < n)
        ans = max(ans , bfs(i+1 , j, matrix) +1 );
    if(j + 1 < m)
        ans = max(ans , bfs(i , j+1, matrix) + 1);
    if(i - 1 >= 0)
        ans = max(ans , bfs(i-1 , j, matrix) +1 );
    if(j - 1 >= 0)
        ans = max(ans , bfs(i , j-1, matrix) + 1);

    dp[i][j] = ans;
    
    return ans;

}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    //Initialization

    n = matrix.size();m = matrix[0].size();

    dp = new int*[n];
    for(int i = 0;i<n;i++)
        dp[i] = new int[m];

    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            dp[i][j] = INT_MIN;

    int maxi = 0;

    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
        {
            maxi = max(maxi , bfs(i , j , matrix));
        }

    return maxi;
}

int main()
{
    vector<vector<int>> inputMat = {{9,9,4},{6,6,8},{2,1,1}};
    cout<<longestIncreasingPath(inputMat);
}