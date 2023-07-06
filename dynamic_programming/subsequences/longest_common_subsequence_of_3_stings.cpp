#include <bits/stdc++.h>
using namespace std;

int dfs(string &a, string &b, string &c, int i, int j, int k, vector<vector<vector<int>>> &dp) {
	if (i<0 or j<0 or k<0) return 0;
	if (dp[i][j][k] != -1) return dp[i][j][k];
	if (a[i]==b[j] and a[i]==c[k]) return dp[i][j][k] = 1+dfs(a, b, c, i-1, j-1, k-1, dp);
	return dp[i][j][k] = max({dfs(a, b, c, i-1, j, k, dp), dfs(a, b, c, i, j-1, k, dp), dfs(a, b, c, i, j, k-1, dp)});
}

int LCS(string A, string B, string C, int n, int m, int k)
{
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
	return dfs(A, B, C, n-1, m-1, k-1, dp);
}