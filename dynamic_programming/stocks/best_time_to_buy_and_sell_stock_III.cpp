#include <bits/stdc++.h> 
using namespace std;
 
int dfs(int index, int buy, int cap, int n, vector<int> &prices, vector<vector<vector<int>>> &dp) {
    if (cap < 0) return -1e9;
    if (index == n) return 0;
    if (dp[index][buy][cap] != -1) return dp[index][buy][cap];
    int profit;
    if (buy) {
        profit = max(-prices[index] + dfs(index+1, 0, cap, n, prices, dp),
                    dfs(index+1, 1, cap, n, prices, dp));
    }
    else {
        profit = max(prices[index] + dfs(index+1, 1, cap-1, n, prices, dp),
                    dfs(index+1, 0, cap, n, prices, dp));
    }
    return dp[index][buy][cap] = profit;
}

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(4, 0)));
    for (int i=0; i<n; i++) dp[i][0][0] = dp[i][1][0] = -1e9;
    for (int i=n-1; i>=0; i--) {
        for (int j=1; j<=3; j++) {
            dp[i][1][j] = max(-prices[i]+dp[i+1][0][j], dp[i+1][1][j]);
            dp[i][0][j] = max(prices[i]+dp[i+1][1][j-1], dp[i+1][0][j]);
        }
    }
    return dp[0][1][3];
}