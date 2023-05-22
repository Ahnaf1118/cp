#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid) {
        int r = grid.size();
        int c = grid[0].size();
        if (i<0 || j<0 || i>= r || j>=c)
            return;
        if (grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(i-1, j, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j] == '0')
                    continue;
                dfs(i, j, grid);
                cnt++;
            }
        }
        return cnt;
    }
};