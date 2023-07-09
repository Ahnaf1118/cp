//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[205][205];
    int dfs(int n, int k) {
        if (n == 1) return k;
        if (k == 0) return 0;
        if (dp[n][k] != -1) return dp[n][k];
        int mn = 2e9;
        for (int i=1; i<=k; i++) {
            mn = min(mn, 1+max(dfs(n-1, i-1), dfs(n, k-i)));
        }
        return dp[n][k] = mn;
    }
    int eggDrop(int n, int k) 
    {
        memset(dp, -1, sizeof(dp));
        return dfs(n, k);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends