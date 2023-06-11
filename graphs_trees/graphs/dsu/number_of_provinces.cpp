//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

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
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> par(V, 0), sz(V, 1);
        for (int i=0; i<V; i++) par[i] = i;
        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                if (i==j or not adj[i][j]) continue;
                merge(i, j, par, sz);
            }
        }
        int cnt = 0;
        for (int i=0; i<V; i++) cnt += (i==par[i]);
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends