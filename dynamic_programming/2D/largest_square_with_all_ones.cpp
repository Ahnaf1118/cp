//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dfs(int i, int j, int &mx, vector<vector<int>> &mat, vector<vector<int>> &dp) {
        if (i >= mat.size() or j >= mat[0].size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mn = min({dfs(i, j+1, mx, mat, dp), dfs(i+1, j, mx, mat, dp), dfs(i+1, j+1, mx, mat, dp)});
        if (not mat[i][j]) return dp[i][j] = 0;
        mx = max(mx, 1 + mn);
        return dp[i][j] = 1 + mn;
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int mx = 0;
        dfs(0, 0, mx, mat, dp);
        return mx;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends