// snakes and transition from capitalism to socialism
#include <bits/stdc++.h>
using namespace std;
const int N = 5e2+10;
int val[N][N];
int vis[N][N];
int lev[N][N];

vector<pair<int, int>> moves = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1},
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
};

void reset() {
    for(int i=0; i<N; i++)
        for (int j=0; j<N; j++) {
            val[i][j] = 0;
            vis[i][j] = 0;
            lev[i][j] = 0;
        }
}

int bfs(int n, int m) {
    int mxv = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            mxv = max(mxv, val[i][j]);
        }
    }
    vector<pair<int, int>> mxs;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (val[i][j] == mxv)
                mxs.push_back({i, j});
        }
    }
    queue<pair<int, int>> q;
    for (auto mx: mxs) {
        q.push(mx);
        vis[mx.first][mx.second] = 1;
    }
    int mxl = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int curx = cur.first;
        int cury = cur.second;
        for (auto move: moves) {
            int cx = move.first + curx;
            int cy = move.second + cury;
            if (cx < 0 || cx >= n || cy < 0 || cy >= m)
                continue;
            if (vis[cx][cy])
                continue;
            q.push({cx, cy});
            vis[cx][cy] = 1;
            lev[cx][cy] = lev[curx][cury] + 1;
            mxl = max(mxl, lev[cx][cy]);
        }
    }
    return mxl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        reset();
        for(int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                cin >> val[i][j];
        cout << bfs(n, m) << endl;
    }
    return 0;
}