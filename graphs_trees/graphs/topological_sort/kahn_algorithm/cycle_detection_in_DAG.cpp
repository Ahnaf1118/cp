//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> in_degree(V, 0);
        for (int i=0; i<V; i++) {
            for (int c: adj[i]) {
                in_degree[c]++;
            }
        }
        queue<int> q;
        for (int i=0; i<V; i++) {
            if (in_degree[i]) continue;
            q.push(i);
        }
        int cnt = 0;
        while (not q.empty()) {
            int v = q.front(); q.pop(); cnt++;
            for (int c: adj[v]) {
                in_degree[c]--;
                if (not in_degree[c]) q.push(c);
            }
        }
        return not (cnt == V);
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