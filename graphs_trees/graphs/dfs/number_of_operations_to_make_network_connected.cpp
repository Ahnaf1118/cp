#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int v, vector<int> &vis, vector<int> graph[]) {
        vis[v] = 1;
        for (int c: graph[v]) {
            if (vis[c]) continue;
            dfs(c, vis, graph);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        vector<int> vis(n, 0), graph[n];
        for (auto connection: connections) {
            int u = connection[0], v = connection[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int cc = 0;
        for (int i=0; i<n; i++) {
            if (vis[i]) continue;
            dfs(i, vis, graph);
            cc++;
        }
        return cc-1;
    }
};