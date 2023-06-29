#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i, int j, vector<int> & values, vector<vector<int>> &dp) {
        if (j-i+1 < 3) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mn = 2e9;
        for (int k=i+1; k<j; k++) {
            mn = min(mn, values[i]*values[k]*values[j] + dfs(i, k, values, dp) + dfs(k, j, values, dp));
        }
        return dp[i][j] = mn;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 2e9));
        for (int i=n-1; i>=0; i--) {
            for (int j=0; j<n; j++) {
                if (j-i+1 < 3) dp[i][j] = 0;
                else for (int k=i+1; k<j; k++) {
                    dp[i][j] = min(dp[i][j], values[i]*values[k]*values[j]  + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};