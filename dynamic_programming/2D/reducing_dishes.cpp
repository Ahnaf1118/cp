#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int index, int k, int n, vector<int> &satisfaction, vector<vector<int>> &dp) {
        if (index >= n) return 0;
        if (dp[index][k] != -99999) return dp[index][k];
        return dp[index][k] = max(dfs(index+1, k, n, satisfaction, dp), satisfaction[index]*k + dfs(index+1, k+1, n, satisfaction, dp));
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int i=0; i<=n; i++) dp[i][0] = dp[n][0] = 0;
        for (int i=n-1; i>=0; i--) {
            for (int j=i; j>=0; j--) {
                dp[i][j] = max(dp[i+1][j], satisfaction[i]*(j+1) + dp[i+1][j+1]);
            }
        }
        int mx = *max_element(dp[0].begin(), dp[0].end());
        return mx;
    }
};