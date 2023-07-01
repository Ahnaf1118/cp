//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int a[], int n) {
       vector<vector<int>> dp(n, vector<int>(*max_element(a, a+n), 1));
       int mx = 1;
       for (int i=1; i<n; i++) {
           for (int j=0; j<i; j++) {
               int diff = a[i] - a[j];
               if (diff == 0) continue;
               dp[i][diff] = max(dp[i][diff], 1 + dp[j][diff]);
               mx = max(mx, dp[i][diff]);
           }
       }
       return mx;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends