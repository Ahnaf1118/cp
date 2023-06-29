#include <bits/stdc++.h>
using namespace std;

// MLE on top-down but bottom-up works
class Solution {
public:
    int dfs(int index, int lane, int n, vector<int> &obstacles, vector<vector<int>> &dp) {
        if (index >= n) return 0;
        if (obstacles[index]-1 == lane) return 1e9;
        if (dp[index][lane] != -1) return dp[index][lane];
        int cost = 2e9;
        for (int i=0; i<3; i++) {
            if (obstacles[index]-1 == i) continue;
            cost = min(cost, 1 + dfs(index+1, i, n, obstacles, dp));
        }
        cost = min(cost, dfs(index+1, lane, n, obstacles, dp));
        return dp[index][lane] = cost;
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(n+1, vector<int>(3, 1e9));
        for (int i=0; i<3; i++) dp[n][i] = 0;
        for (int i=n-1; i>=0; i--) {
            for (int j=0; j<3; j++) {
                if (obstacles[i]-1 == j) continue;
                for (int k=0; k<3; k++) {
                    if (obstacles[i]-1 == k) continue;
                    dp[i][j] = min(dp[i][j], 1+dp[i+1][k]);
                }
                dp[i][j] = min(dp[i][j], dp[i+1][j]);
            }
        }
        return dp[0][1];
    }
};