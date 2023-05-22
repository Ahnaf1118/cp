#include <bits/stdc++.h>
using namespace std;
const int N = 510;
vector<string> maze(510);
vector<pair<int, int>> xys;
bool vis[510][510];

void reset(int n, int m) {
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            vis[i][j] = false;
        }
}

void dfs(int i, int j, int n, int m) {
    if (i<0 || i>=n || j<0 || j>=m || maze[i][j] == '#')
        return;
    if (vis[i][j])
        return;
    vis[i][j] = true;
    xys.push_back({i, j});
    dfs(i-1, j, n, m);
    dfs(i+1, j, n, m);
    dfs(i, j-1, n, m);
    dfs(i, j+1, n, m);
}

void print(int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    reset(n, m);
    cin.ignore();
    for (int i=0; i<n; i++) {
        cin >> maze[i];
    }
    int x=0, y=0;
    bool found = false;
    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            if (maze[i][j] == '.') {
                x = i, y = j;
                found = true;
                break;
        }
        if (found)
            break;
    }
    dfs(x, y, n, m);
    // print(n, m);
    // bfs(x, y, n, m);
    int w = 0;
    for (int i=xys.size()-1; i>=0; i--) {
        if (w==k)
            continue;
        maze[xys[i].first][xys[i].second] = 'X';
        w++;
    }
    print(n, m);
    return 0;
}