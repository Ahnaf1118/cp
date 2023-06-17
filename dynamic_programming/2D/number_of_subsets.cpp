#include <bits/stdc++.h> 
using namespace std;

//topdown
int dfs(int ind, int tar, vector<int> &num, vector<vector<int>> &dp) {
    if (tar == 0) return 1;
    if (ind == 0) return num[0]==tar;
    if (dp[ind][tar] != -1) return dp[ind][tar];
    int ways = dfs(ind-1, tar, num, dp);
    if (num[ind] <= tar) ways += dfs(ind-1, tar-num[ind], num, dp);
    return dp[ind][tar] = ways;
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    sort(num.begin(), num.end());
    vector<vector<int>> dp(n, vector<int>(tar+1, -1));
    return dfs(n-1, tar, num, dp);
}

//bottom up
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    sort(num.begin(), num.end(), greater<int>());
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));
    for (int i=0; i<n; i++) dp[i][0] = 1;
    if (num[0] <= tar) dp[0][num[0]] = 1;
    for (int i=1; i<n; i++) {
        for (int j=0; j<=tar; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-num[i] >= 0) dp[i][j] += dp[i-1][j-num[i]];
        }
    }
    return dp[n-1][tar];
}