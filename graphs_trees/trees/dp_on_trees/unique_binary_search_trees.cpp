#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int n, vector<int> &dp) {
        if (n<=1) return 1;
        if (dp[n] != -1) return dp[n];
        int res = 0;
        for (int i=1; i<=n; i++) res += dfs(i-1, dp)*dfs(n-i, dp);
        return dp[n] = res;
    }
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return dfs(n, dp);
    }
};