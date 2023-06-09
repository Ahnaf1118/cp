//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int v, vector<int> &color, vector<int> adj[]) {
        color[v] = 2;
        for (int c: adj[v]) {
            if (color[c] == 0) {
                if (dfs(c, color, adj)) return true;
            }
            else if (color[c] == 2) return true;
        }
        color[v] = 1;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> color(V+1, 0);
        for (int i=0; i<V; i++) 
            if (dfs(i, color, adj)) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends