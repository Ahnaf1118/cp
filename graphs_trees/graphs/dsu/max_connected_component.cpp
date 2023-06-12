//{ Driver Code Starts
// Initial Template for C++

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
        int pu = find(u, par), pv = find(v, par);
        if (pu == pv) return;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
    }
    bool in_range(int i, int j, int n, int m, vector<vector<int>> &grid) {
        return (i>=0 and i<n and j>=0 and j<m and grid[i][j]);
    }
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> par(n*m, 0), sz(n*m, 0);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int u = i*m+j;
                par[u] = u;
                sz[u] = (grid[i][j]);
                if (not sz[u]) continue;
                if (in_range(i-1, j, n, m, grid)) {
                    int ch = (i-1)*m+j;
                    merge(u, ch, par, sz);
                }
                if (in_range(i, j-1, n, m, grid)) {
                    int ch = i*m+(j-1);
                    merge(u, ch, par, sz);
                }
            }
        }
        int mx = *max_element(sz.begin(), sz.end());
        int xs[] = {0, 0, -1, 1}, ys[] = {-1, 1, 0, 0};
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]) continue;
                int temp = 1; 
                set<int> st;
                for (int k=0; k<4; k++) {
                    int x = i+xs[k], y = j+ys[k];
                    if (not in_range(x, y, n, m, grid)) continue;
                    int up = find(x*m+y, par);
                    if (st.count(up)) continue;
                    st.insert(up);
                    temp += sz[up];
                }
                st.clear();
                mx = max(mx, temp);
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
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends