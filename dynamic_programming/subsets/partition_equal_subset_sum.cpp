#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int> &arr, int n)
{
	int sum = accumulate(arr.begin(), arr.end(), 0);
	if (sum & 1) return false;
	sum /= 2;
	vector<vector<bool>> dp(105, vector<bool>(1e4+10, 0));
	for (int i=0; i<n; i++) dp[i][0] = 1;
	dp[0][arr[0]] = 1;
	for (int i=1; i<n; i++) {
		for (int j=0; j<=sum; j++) {
			dp[i][j] = dp[i-1][j];
			if (j-arr[i]>=0) dp[i][j] = dp[i][j] or dp[i-1][j-arr[i]];
		}
	}
	return dp[n-1][sum];
}
