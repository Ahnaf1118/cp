//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int countBT(int n) { 
        vector<int> dp(n+3, 0);
        dp[0] = dp[1] = 1; int M = 1e9+7;
        for (int i=2; i<=n; i++) {
            dp[i] = (dp[i-1]*1ll*((((2ll*dp[i-2])%M)+dp[i-1])%M))%M;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends