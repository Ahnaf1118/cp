//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
	public:
	int dfs(int index, int wt, int n, int cost[], vector<vector<int>> &dp) {
	    if (wt < 0) return 1e9;
	    if (index == n) return (wt==0)?0:1e9;
	    if (dp[index][wt] != -1) return dp[index][wt];
	    int mn = 1e9;
	    mn = min(mn, dfs(index+1, wt, n, cost, dp));
	    if (cost[index] != -1) mn = min(mn, cost[index] + dfs(index, wt-(index+1), n, cost, dp));
	    return dp[index][wt] = mn;
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
	    vector<vector<int>> dp(N, vector<int>(W+1, -1));
        int res = dfs(0, W, N, cost, dp);
        if (res == (int)(1e9)) res = -1;
        return res;
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends