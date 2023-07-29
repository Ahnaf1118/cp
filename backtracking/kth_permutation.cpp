//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int fact(int n) {
        if (n==0) return 1;
        return n*fact(n-1);
    }
    void dfs(int n, int k, set<int> st, string &path, string &res) {
        if (st.size() == 1) {
            path.push_back(*st.begin()+'0');
            res = path;
            return;
        }
        int rem = fact(st.size()-1);
        int index = k/rem;
        auto it = next(st.begin(), index);
        st.erase(it);
        path.push_back(*it+'0');
        dfs(n, k%rem, st, path, res);
        path.pop_back();
        st.insert(*it);
    }
    string kthPermutation(int n, int k)
    {
        string res, path;
        set<int> st;
        for (int i=1; i<=n; i++) st.insert(i);
        dfs(n, k-1, st, path, res);
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends