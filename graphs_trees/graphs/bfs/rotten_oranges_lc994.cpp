#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_valid(int i, int j, int n, int m, vector<vector<int>> &visited, vector<vector<int>> &grid) {
        if (i<0 or i>=n) return false;
        if (j<0 or j>=m) return false;
        if (visited[i][j]) return false;
        if (grid[i][j] == 0 or grid[i][j] == 2) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> depth(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 2) q.push({i, j});
            }
        }
        while(!q.empty()) {
            auto pr = q.front(); q.pop();
            int i = pr.first, j = pr.second;
            int cur_depth = depth[i][j];
            if (is_valid(i+1, j, n, m, visited, grid)) {
                visited[i+1][j] = 1;
                depth[i+1][j] = cur_depth + 1;
                q.push({i+1, j}); 
            }
            if (is_valid(i-1, j, n, m, visited, grid)) {
                visited[i-1][j] = 1;
                depth[i-1][j] = cur_depth + 1;
                q.push({i-1, j}); 
            }
            if (is_valid(i, j+1, n, m, visited, grid)) {
                visited[i][j+1] = 1;
                depth[i][j+1] = cur_depth + 1;
                q.push({i, j+1}); 
            }
            if (is_valid(i, j-1, n, m, visited, grid)) {
                visited[i][j-1] = 1;
                depth[i][j-1] = cur_depth + 1;
                q.push({i, j-1}); 
            }
        }
        int mx = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) {
                    if (depth[i][j] == 0) return -1;
                    else mx = max(mx, depth[i][j]);
                }
            }
        }
        return mx;
    }
};