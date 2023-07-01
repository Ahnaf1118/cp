#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &dp) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mn = 2e9;
        for (int k=i; k<=j; k++) {
            mn = min(mn, k + max(dfs(i, k-1, dp), dfs(k+1, j, dp)));
        }
        return dp[i][j] = mn;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return dfs(1, n, dp);
    }
};