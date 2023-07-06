#include <bits/stdc++.h> 
using namespace std;

int dfs(int index, int k, int inc, int n, vector<int> &post, vector<vector<int>> &dp) {
	if (k < 0) return -1e9;
	if (index >= n) return (k==0)?0:-1e9;
	if (dp[index][k] != -1) return dp[index][k];
	return dp[index][k] = max(dfs(index+1, k, inc, n, post, dp), post[index] + dfs(index+inc, k-1, inc, n, post, dp));
}
int maxSumTwoSubarray(int arr[], int N, int K)
{
	vector<int> post(N, 0);
	post[N-1] = arr[N-1];
	for (int i=N-1; i>=0; i--) {
		if (i+1 >= N) continue;
		post[i] = arr[i] + post[i+1]; 
	}
	for (int i=0; i<N; i++) {
		if (i+K >= N) continue;
		post[i] -= post[i+K];
	}
	vector<vector<int>> dp(N, vector<int>(3, -1));
	return dfs(0, 2, K, N-K+1, post, dp);
}
