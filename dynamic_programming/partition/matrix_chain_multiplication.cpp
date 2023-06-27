#include <bits/stdc++.h> 
using namespace std;

int matrixMultiplication(vector<int> &arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    for (int i=n-1; i>=0; i--) {
        dp[i][i] = 0;
        for (int j=i+1; j<n; j++) {
            for (int k=i; k<j; k++) {
                dp[i][j] = min(dp[i][j], arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j]);
            }
        }
    }
    return dp[1][n-1];
}