#include <bits/stdc++.h>
using namespace std;

// modified house robber 2
class Solution {
public:
    int dfs(int index, int k, int n, vector<int> &slices, vector<vector<int>> &dp) {
        if (index >= n or not k) return 0;
        if (dp[index][k] != -1) return dp[index][k];
        return dp[index][k] = max(dfs(index+1, k, n, slices, dp), slices[index] + dfs(index+2, k-1, n, slices, dp));
    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp1(n, vector<int>(n, -1)), dp2(n, vector<int>(n, -1));
        int op1 = dfs(0, n/3, n-1, slices, dp1);
        int op2 = dfs(1, n/3, n, slices, dp2);
        return max(op1, op2);
    }
};