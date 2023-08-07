#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int INF = 1e9;
    int bfs(int start, int n, map<int, int> &mp) {
        queue<int> q;
        set<int> st;
        q.push(start), st.insert(start);
        int steps = 0;
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                int index = q.front(); q.pop();
                if (index == n*n) return steps;
                for (int i=index+1; i<=min(n*n, index+6); i++) {
                    int next = mp.count(i)? mp[i]: i;
                    if (st.count(next)) continue;
                    q.push(next), st.insert(next);
                }
            }
            steps++;
        }
        return -1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        map<int, int> mp;
        int n = board.size();
        vector<int> arr = {0};
        for (int i=0; i<n/2; i++) swap(board[i], board[n-i-1]);
        for (int i=0; i<n; i++) {
            if (i&1) for (int j=0; j<n/2; j++) {
                swap(board[i][j], board[i][n-j-1]);
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == -1) continue;
                mp[i*n + j + 1] = board[i][j];
            }
        }
        return bfs(1, n, mp);
    }
};