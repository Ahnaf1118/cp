#include <bits/stdc++.h> 
using namespace std;

int dfs(int index, int buy, int n, vector<int> &prices, vector<vector<int>> &dp) {
    if (index >= n) return 0;
    if (dp[index][buy] != -1) return dp[index][buy];
    int profit = 0;
    if (buy) {
        profit = max(-prices[index] + dfs(index+1, 0, n, prices, dp), 
                    dfs(index+1, 1, n, prices, dp));
    }
    else {
        profit = max(prices[index] + dfs(index+2, 1, n, prices, dp),
                    dfs(index+1, 0, n, prices, dp));
    }
    return dp[index][buy] = profit;
}

int stockProfit(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+2, vector<int>(2, 0));
    for (int i=n-1; i>=0; i--) {
        dp[i][1] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
        dp[i][0] = max(prices[i]+dp[i+2][1], dp[i+1][0]);
    }
    return dp[0][1];
}