#include <bits/stdc++.h>
using namespace std;

int dfs(int i, int j, vector<int> &arr, vector<int> &pre, vector<vector<int>> &dp) {
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int mn = 2e9;
    for (int k=i; k<j; k++) {
        mn = min(mn, pre[j+1]-pre[i]+dfs(i, k, arr, pre, dp) + dfs(k+1, j, arr, pre, dp));
    }
    return dp[i][j] = mn;
}

int findMinCost(vector<int> &arr, int n){
    vector<int> pre(n+1, 0), post;
    for (int i=1; i<n+1; i++) pre[i] = pre[i-1]+arr[i-1];
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return dfs(0, n-1, arr, pre, dp);
}