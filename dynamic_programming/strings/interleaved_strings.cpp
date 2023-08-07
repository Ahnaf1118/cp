//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    bool dfs(int i, int j, int &n, int &m, string &a, string &b, string &c, vector<vector<int>> &dp) {
        if (i == n and j == m) return true;
        if (dp[i][j] != -1) return dp[i][j];
        bool res = false;
        if (i < n and a[i] == c[i+j]) res = res or dfs(i+1, j, n, m, a, b, c, dp);
        if (j < m and b[j] == c[i+j]) res = res or dfs(i, j+1, n, m, a, b, c, dp); 
        return dp[i][j] = res;
    }
    bool isInterleave(string a, string b, string c) 
    {
        int n = a.size(), m = b.size();
        if (n + m != c.size()) return false;
        vector<vector<int>> dp(n+10, vector<int>(m+10, -1));
        return dfs(0, 0, n, m, a, b, c, dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends