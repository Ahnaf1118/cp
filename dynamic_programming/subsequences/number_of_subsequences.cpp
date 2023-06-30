#include <bits/stdc++.h> 
using namespace std;

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    int n = lt, m = ls, M = 1e9+7;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i=0; i<=n; i++) dp[i][0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (t[i-1]==s[j-1]) dp[i][j] = (dp[i-1][j-1] + 0ll + dp[i-1][j]) % M;
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][m];
} 