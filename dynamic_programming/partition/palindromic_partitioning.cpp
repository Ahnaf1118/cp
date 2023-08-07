//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i=n; i>=0; i--) {
            for (int j=0; j<n; j++) {
                if (i > j) continue;
                if (i == j) dp[i][j] = 1;
                else if (j-i+1 == 2) dp[i][j] = (str[i]==str[j]);
                else if (str[i] == str[j]) dp[i][j] = dp[i+1][j-1];
            }
        }
        vector<int> res(n, 0);
        for (int i=0; i<n; i++) {
            if (dp[0][i]) continue;
            res[i] = 2e9;
            for (int j=0; j<i; j++) {
                if (not dp[j+1][i]) continue;
                res[i] = min(res[i], 1+res[j]);
            }
        }
        return res[n-1];
    }
};

class Solution{
public:
    bool check(string &s) {
        for (int i=0; i<s.size()/2; i++) if (s[i] != s[s.size()-1-i]) return false;
        return true;
    }
    int dfs(int index, int &n, string &s, vector<int> &dp) {
        if (index == n) return 0;
        if (dp[index] != -1) return dp[index];
        int mn = 1e9;
        for (int i=index; i<n; i++) {
            string cur = s.substr(index, i-index+1);
            if (not check(cur)) continue;
            mn = min(mn, 1 + dfs(i+1, n, s, dp));
        }
        return dp[index] = mn;
    }
    int palindromicPartition(string s)
    {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for (int i=n-1; i>=0; i--) {
            int mn = 1e9;
            for (int j=i; j<n; j++) {
                string cur = s.substr(i, j-i+1);
                if (not check(cur)) continue;
                mn = min(mn, 1 + dp[j+1]);
            }
            dp[i] = mn;
        }
        return max(0, dp[0]-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends