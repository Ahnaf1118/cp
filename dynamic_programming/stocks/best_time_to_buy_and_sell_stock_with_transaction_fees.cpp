#include <bits/stdc++.h> 
using namespace std;

int maximumProfit(int n, int fee, vector<int> &prices) {
    vector<vector<int>> dp(n+1, vector<int>(2, 0));
    for (int i=n-1; i>=0; i--) {
        dp[i][1] = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
        dp[i][0] = max(prices[i]-fee+dp[i+1][1], dp[i+1][0]);
    }
    return dp[0][1];
}
