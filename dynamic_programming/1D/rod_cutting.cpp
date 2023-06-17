#include <bits/stdc++.h>
using namespace std;

int dfs(int length, int n, vector<int> &price, vector<int> &dp) {
	if (length < 0) return -1e9;
	if (length == 0) return 0;
	if (dp[length] != -1) return dp[length];
	int mx = 0;
	for (int i=1; i<=n; i++) {
		mx = max(mx, price[i-1] + dfs(length-i, n, price, dp));
	}
	return dp[length] = mx;
}

int cutRod(vector<int> &price, int n)
{
	vector<int> dp(n+1, -1e9);
	dp[0] = 0;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (j-i < 0) continue;
			dp[j] = max(dp[j], price[i-1] + dp[j-i]);
		}
	}
	return dp[n];
}
