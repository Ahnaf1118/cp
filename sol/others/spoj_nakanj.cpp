// spoj nakanj
#include <bits/stdc++.h>
using namespace std;
bool vis[8][8];
int level[8][8];

vector<pair<int, int>> moves = {
    {2, -1},
    {2, 1},
    {-2, 1},
    {-2, -1},
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2}
};

void reset() {
    for (int i=0; i<8; i++)
        for(int j=0; j<8; j++) {
            vis[i][j] = 0;
            level[i][j] = INT_MAX;
        }
}

int getX(string x) {
    return x[0]-'a';
}
int getY(string y) {
    return y[1]-'1';
}

int bfs(string src, string dst) {
    int x1 = getX(src);
    int y1 = getY(src);
    int x2 = getX(dst);
    int y2 = getY(dst);
    queue<pair<int, int>> q;
    q.push({x1,y1});
    vis[x1][y1] = 1;
    level[x1][y1] = 0;
    while(!q.empty()) {
        pair<int, int> pr = q.front();
        q.pop();
        for (auto move: moves) {
            int x = pr.first + move.first;
            int y = pr.second + move.second;
            if (x < 0 || x >= 8 || y < 0 || y >= 8)
                continue;
            if (vis[x][y])
                continue;
            q.push({x, y});
            vis[x][y] = 1;
            level[x][y] = level[pr.first][pr.second] + 1;
        }
        if (level[x2][y2] != INT_MAX)
            break;
    }
    return level[x2][y2];
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        reset();
        string src, dst;
        cin >> src >> dst;
        cout << bfs(src, dst) << endl;
    }
}