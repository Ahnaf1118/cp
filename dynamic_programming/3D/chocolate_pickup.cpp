#include <bits/stdc++.h> 
using namespace std;

int dfs(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    if (i<0 or j1<0 or j2<0 or i>=r or j1>=c or j2>=c) return -1e9;
    if (i==r-1) {
        if (j2 == j1) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
    int mx = 0;
    for (int d1=-1; d1<=1; d1++) {
        for (int d2=-1; d2<=1; d2++) {
            int value = 0;
            if (j1 == j2) value += grid[i][j1];
            else value += grid[i][j1] + grid[i][j2];
            value += dfs(i+1, j1+d1, j2+d2, r, c, grid, dp);
            mx = max(mx, value);
        }
    }
    return dp[i][j1][j2] = mx;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return dfs(0, 0, c-1, r, c, grid, dp);
}