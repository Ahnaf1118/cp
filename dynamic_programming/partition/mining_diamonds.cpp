#include <bits/stdc++.h> 
using namespace std;

int dfs(int i, int j, vector<int> &a, vector<vector<int>> &dp) {
	if (i>j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int mx = 0;
	for (int k=i; k<=j; k++) {
		mx = max(mx, a[i-1]*a[k]*a[j+1] + dfs(i, k-1, a, dp) + dfs(k+1, j, a, dp));
	}
	return dp[i][j] = mx;
}

int maxCoins(vector<int>& a)
{
	a.insert(a.begin(), 1); a.push_back(1);
	int n = a.size();
	vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
	for (int i=n-1; i>=0; i--) {
		for (int j=1; j<=n-2; j++) {
			if (i > j) continue;
			for (int k=i; k<=j; k++) 
				dp[i][j] = max(dp[i][j], a[i-1]*a[k]*a[j+1] + dp[i][k-1] + dp[k+1][j]);
		}
	}
	return dp[1][n-2];
}