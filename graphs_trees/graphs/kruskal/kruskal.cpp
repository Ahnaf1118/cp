//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void make(int n, vector<int> &par) {
	    for (int i=0; i<n; i++) par[i] = i;
	}
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
	static bool compare(vector<int> &v1, vector<int> &v2) {
	    return v1[2] < v2[2];
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
    	vector<int> par(V, 0), sz(V, 1);
        vector<vector<int>> edges;
        for (int i=0; i<V; i++) {
            for (auto ch: adj[i]) {
                edges.push_back({i, ch[0], ch[1]});
            }
        }
        make(V, par);
        sort(edges.begin(), edges.end(), compare);
        int total = 0, cnt = 0;
        for (auto edge: edges) {
            if (cnt == V-1) break;
            int u = edge[0], v = edge[1], cost = edge[2];
            if (find(u, par) == find(v, par)) continue;
            merge(u, v, par, sz);
            total += cost;
        }
        return total;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends