#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i, int j, int r, int c, vector<vector<char>> &board) {
        if (i < 0 || j < 0 || i>=r || j >= c || board[i][j] != 'O')
            return;
        board[i][j] = '#';
        dfs(i+1, j, r, c, board);
        dfs(i-1, j, r, c, board);
        dfs(i, j+1, r, c, board);
        dfs(i, j-1, r, c, board);
    }
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        for (int i=0; i<r; i++) {
            if (board[i][0]=='O') {
                dfs(i, 0, r, c, board);
            }
            if (board[i][c-1]=='O') {
                dfs(i, c-1, r, c, board);
            }
        }
        for (int i=0; i<c; i++) {
            if (board[0][i]=='O') {
                dfs(0, i, r, c, board);
            }
            if (board[r-1][i]=='O') {
                dfs(r-1, i, r, c, board);
            }
        }
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};