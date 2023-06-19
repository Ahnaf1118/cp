#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n+1, vector<long>(2, 0));
    for (int i=n-1; i>=0; i--) {
        dp[i][0] = max(values[i] + dp[i+1][1], dp[i+1][0]);
        dp[i][1] = max(-values[i] + dp[i+1][0], dp[i+1][1]);
    }
    return dp[0][1];
}