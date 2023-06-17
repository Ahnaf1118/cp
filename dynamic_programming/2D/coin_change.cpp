#include <bits/stdc++.h>
using namespace std;

long dfs(int index, int value, int n, int *denominations, vector<vector<long>> &dp) {
    if (value < 0) return 0;
    if (index >= n) return value == 0;
    if (dp[index][value] != -1) return dp[index][value];
    long ways = dfs(index, value-denominations[index], n, denominations, dp)
                + dfs(index+1, value, n, denominations, dp);
    return dp[index][value] = ways;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    sort(denominations, denominations+n);
    vector<vector<long>> dp(n, vector<long>(value+1, 0));
    dp[0][0] = 1;
    for (int i=0; i<=value; i++) dp[0][i] = (i%denominations[0]==0);
    for (int i=1; i<n; i++) {
        for (int j=0; j<=value; j++) {
            dp[i][j] += dp[i-1][j];
            if (j-denominations[i] >= 0) dp[i][j] += dp[i][j-denominations[i]];
        }
    }
    return dp[n-1][value];
}