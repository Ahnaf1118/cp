//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int find(int u, vector<int> &par) {
        if (u == par[u]) return u;
        return par[u] = find(par[u], par);
    }
    void merge(int u, int v, vector<int> &par, vector<int> &sz) {
        int pu = par[u], pv = par[v];
        if (pu == pv) return;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
    }
    int Solve(int n, vector<vector<int>>& edges) {
        vector<int> par(n, 0), sz(n, 1);
        for (int i=0; i<n; i++) par[i] = i;
        int extra = 0;
        for (auto edge: edges) {
            int u = edge[0], v = edge[1];
            if (find(u, par) == find(v, par)) extra++;
            else merge(u, v, par, sz);
        }
        int cnt = 0;
        for (int i=0; i<n; i++) cnt += (i==par[i]);
        return (extra>=(cnt-1)?cnt-1:-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends