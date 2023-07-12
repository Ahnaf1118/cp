#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int i, int j, vector<int> &arr, vector<vector<int>> &mx, vector<vector<int>> &dp) {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mn = 2e9;
        for (int k=i; k<j; k++) {
            mn = min(mn, mx[i][k]*mx[k+1][j] + dfs(i, k, arr, mx, dp)+dfs(k+1, j, arr, mx, dp));
        }
        return dp[i][j] = mn;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> mx(n, vector<int>(n, 0)), dp(n+1, vector<int>(n+1, -1));
        for (int i=0; i<n; i++) {
            mx[i][i] = arr[i];
            for (int j=i+1; j<n; j++) {
                mx[i][j] = max(arr[j], mx[i][j-1]);
            }
        }
        return dfs(0, n-1, arr, mx, dp);
    }
};