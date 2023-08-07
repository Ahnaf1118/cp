//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    const int M = 1003;
    int dp[205][205][5];
    int dfs(int i, int j, bool can, string &s) {
        if (i > j) return 0;
        if (i == j) {
            if (can) return s[i]=='T';
            else return s[i]=='F';
        }
        if (dp[i][j][can] != -1) return dp[i][j][can];
        int ways = 0;
        for (int k=i+1; k<j; k+=2) {
            int lt = dfs(i, k-1, 1, s), lf = dfs(i, k-1, 0, s);
            int rt = dfs(k+1, j, 1, s), rf = dfs(k+1, j, 0, s);
            if (s[k] == '&') {
                if (can) ways = (ways + (lt*rt)%M)%M;
                else ways = (ways + (lf*rf)%M + (lf*rt)%M + (lt*rf)%M)%M;
            }
            else if (s[k] == '|') {
                if (can) ways = (ways + (lf*rt)%M + (lt*rf)%M + (lt*rt)%M)%M;
                else ways = (ways + (lf*rf)%M)%M;
            }
            else {
                if (can) ways = (ways + (lf*rt)%M + (lt*rf)%M)%M;
                else ways = (ways + (lf*rf)%M + (lt*rt)%M)%M;
            }
        }
        return dp[i][j][can] = ways;
    }
    int countWays(int n, string s){
        memset(dp, -1, sizeof(dp));
        return dfs(0, n-1, 1, s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends