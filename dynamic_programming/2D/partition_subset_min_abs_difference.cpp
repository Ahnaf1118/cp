#include <bits/stdc++.h> 
using namespace std;
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int total = accumulate(arr.begin(), arr.end(), 0);
	vector<vector<bool>> dp(n+1, vector<bool>(total+1, 0));
	for (int i=0; i<n; i++) dp[i][0] = 1;
	dp[0][arr[0]] = 1;
	for (int i=1; i<n; i++) {
		for (int j=1; j<=total; j++) {
			dp[i][j] = dp[i-1][j];
			if (j-arr[i] >= 0) dp[i][j] = dp[i][j] or dp[i-1][j-arr[i]];
		}
	}
	int mn = 1e9;
	for (int i=0; i<=total; i++) {
		if (not dp[n-1][i]) continue;
		mn = min(mn, abs(total - 2*i));
	}
	return mn;
}
