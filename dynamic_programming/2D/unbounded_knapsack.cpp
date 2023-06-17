#include <bits/stdc++.h> 
using namespace std;

int dfs(int index, int wt, int n, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {
    if (wt < 0) return -1e9;
    if (index >= n) return 0;
    if (dp[index][wt] != -1) return dp[index][wt];
    int mx = max(dfs(index+1, wt, n, profit, weight, dp), profit[index] + dfs(index, wt-weight[index], n, profit, weight, dp));
    return dp[index][wt] = mx;
}
int unboundedKnapsack(int n, int wt, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(wt+1, 0));
    dp[0][0] = 0;
    for (int i=0; i<=wt; i++) if (i-weight[0] >= 0) dp[0][i] = profit[0] + dp[0][i-weight[0]];
    for (int i=1; i<n; i++) {
      for (int j = 0; j <= wt; j++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        if (j - weight[i] >= 0)
          dp[i][j] = max(dp[i][j], profit[i] + dp[i][j - weight[i]]);
      }
    }
    return dp[n-1][wt];
}
