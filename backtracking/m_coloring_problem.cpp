//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool check(int vertex, int color, vector<int> &colors, bool graph[101][101]) {
        for (int i=0; i<101; i++) {
            if (graph[vertex][i] and color == colors[i]) return false;
        }
        return true; 
    }
    bool dfs(int vertex, int n, int m, vector<int> &colors, bool graph[101][101]) {
        if (vertex == n) return true;
        for (int i=1; i<=m; i++) {
            if (not check(vertex, i, colors, graph)) continue;
            colors[vertex] = i;
            if (dfs(vertex+1, n, m, colors, graph)) return true;
            colors[vertex] = 0;
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> colors(n, 0);
        return dfs(0, n, m, colors, graph);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends