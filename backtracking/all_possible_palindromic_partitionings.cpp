//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool check(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return (s==t);
    }
    void dfs(int index, int n, string s, vector<string> &path, vector<vector<string>> &res) {
        if (index == n) {
            res.push_back(path);
            return;
        }
        for (int i=index; i<n; i++) {
            string sub = s.substr(index, i-index+1);
            if (not check(sub)) continue;
            path.push_back(sub);
            dfs(i+1, n, s, path, res);
            path.pop_back();
        }
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        vector<string> path;
        vector<vector<string>> res;
        int n = s.size();
        dfs(0, n, s, path, res);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends