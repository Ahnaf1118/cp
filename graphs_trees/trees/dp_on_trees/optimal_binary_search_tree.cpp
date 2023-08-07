//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dfs(int i, int j, int freq[], vector<vector<int>> &dp) {
        if (i > j) return 0;
        if (i == j) return freq[i];
        if (dp[i][j] != -1) return dp[i][j];
        int sum = accumulate(freq+i, freq+j+1, 0);
        int mn = 2e9;
        for (int k=i; k<=j; k++) {
            mn = min(mn, sum + dfs(i, k-1, freq, dp) + dfs(k+1, j, freq, dp));
        }
        return dp[i][j] = mn;
    }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(0, n-1, freq, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends