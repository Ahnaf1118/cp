//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i, int j, int n, int m, vector<vector<int>> &visited, vector<vector<int>> &grid, vector<pair<int, int>> &pairs, int x, int y) {
        if (i<0 or i>=n or j<0 or j>=m) return;
        if (visited[i][j]) return;
        if (grid[i][j] == 0) return;
        visited[i][j] = 1;
        pairs.push_back({i-x, j-y});
        dfs(i+1, j, n, m, visited, grid, pairs, x, y);
        dfs(i-1, j, n, m, visited, grid, pairs, x, y);
        dfs(i, j-1, n, m, visited, grid, pairs, x, y);
        dfs(i, j+1, n, m, visited, grid, pairs, x, y);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (visited[i][j] or not grid[i][j]) continue;
                vector<pair<int, int>> pairs;
                dfs(i, j, n, m, visited, grid, pairs, i, j);
                st.insert(pairs);
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends