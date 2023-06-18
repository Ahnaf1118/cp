#include <bits/stdc++.h> 
using namespace std;

int dfs(int i, int j, int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
	if (i>=n or j>=m) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int cnt = 0;
	for (int k=0; k<min(n-i, m-j); k++) {
		if (s1[i+k] != s2[j+k]) break;
		cnt++;
	}
	int mx = max({cnt, dfs(i+1, j, n, m, s1, s2, dp), dfs(i, j+1, n, m, s1, s2, dp)});
	return dp[i][j] = mx;
}
int lcs(string &str1, string &str2){
	int n = str1.size(), m = str2.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
		}
	}
	int mx = 0;
	for (int i=0; i<=n; i++) mx = max(mx, *max_element(dp[i].begin(), dp[i].end()));
	return mx;
}