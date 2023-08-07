//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int dfs(int v, int mask, int n, vector<vector<int>> &cost, vector<vector<int>> &dp) {
        if (mask == (1<<n)-1) return cost[v][0];
        if (dp[v][mask] != -1) return dp[v][mask];
        int mn = 2e9;
        for (int i=0; i<n; i++) {
            int cur = (1<<i);
            if (mask & cur) continue;
            mn = min(mn, cost[v][i] + dfs(i, mask|cur, n, cost, dp));
        }
        return dp[v][mask] = mn;
    }
    int total_cost(vector<vector<int>> &cost){
        int n = cost.size();
        if (n == 1) return 0;
        vector<vector<int>> dp(n+10, vector<int>((1<<n)+10, -1));
        return dfs(0, 1, n, cost, dp);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends