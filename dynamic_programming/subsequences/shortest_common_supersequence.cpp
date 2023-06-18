#include <bits/stdc++.h> 
using namespace std;

string shortestSupersequence(string a, string b)
{
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	int i = n, j = m;
	string res = "";
	while(i>0 and j>0) {
		if (a[i-1]==b[j-1]) res.push_back(a[i-1]), i--, j--;
		else {
			int up = dp[i-1][j], left = dp[i][j-1];
			if (up > left) res.push_back(a[i-1]), i--;
			else res.push_back(b[j-1]), j--;
		}
	}
	while (j>0) res.push_back(b[j-1]), j--;
	while (i>0) res.push_back(a[i-1]), i--;
	reverse(res.begin(), res.end());
	return res;
}