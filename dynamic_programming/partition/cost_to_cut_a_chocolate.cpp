#include <bits/stdc++.h> 
using namespace std;

int dfs(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int mn = 1e9;
    for (int k=i; k<=j; k++) {
        mn = min(mn, -cuts[i-1]+cuts[j+1]+dfs(i, k-1, cuts, dp)+dfs(k+1, j, cuts, dp));
    }
    return dp[i][j] = mn;
}

int cost(int n, int c, vector<int> &cuts){
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
    for (int i=c; i>=1; i--) {
        for (int j=1; j<=c; j++) {
            long long mn = 1e9;
            if (i > j) mn = 0;
            else for (int k=i; k<=j; k++) {
                mn = min(mn, 0ll-cuts[i-1]+cuts[j+1]+dp[i][k-1]+dp[k+1][j]);
            }
            dp[i][j] = mn;
        }
    }
    return dp[1][c];
}