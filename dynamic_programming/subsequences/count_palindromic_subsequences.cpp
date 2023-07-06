//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    int dfs(int i, int j, string &s, vector<vector<int>> &dp) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) return dp[i][j] = (1ll+dfs(i+1, j, s, dp)+dfs(i, j-1, s, dp)) % (int)(1e9+7);
        else return dp[i][j] = (0ll+dfs(i+1, j, s, dp)+dfs(i, j-1, s, dp)+(int)(1e9+7)-dfs(i+1, j-1, s, dp)) % (int)(1e9+7);
    } 
    long long int  countPS(string s)
    {
       int n = s.size();
       vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
       return dfs(0, n-1, s, dp);
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends