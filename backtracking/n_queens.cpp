#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int index, int n, set<int> &cols, set<int> &neg, set<int> &pos, vector<string> &grid, vector<vector<string>> &res) {
        if (index == n) {
            res.push_back(grid);
            return;
        }
        for (int i=0; i<n; i++) {
            if (cols.count(i) or neg.count(index-i) or pos.count(index+i)) continue;
            cols.insert(i), neg.insert(index-i), pos.insert(index+i);
            grid[index][i] = 'Q';
            dfs(index+1, n, cols, neg, pos, grid, res);
            grid[index][i] = '.';
            cols.erase(i), neg.erase(index-i), pos.erase(index+i);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> grid;
        string row;
        for (int i=0; i<n; i++) row.push_back('.');
        for (int i=0; i<n; i++) grid.push_back(row);
        set<int> cols, neg, pos;
        dfs(0, n, cols, neg, pos, grid, res);
        return res;
    }
};