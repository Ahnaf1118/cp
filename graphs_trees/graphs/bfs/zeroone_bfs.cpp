#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<pair<int, int>> graph[N];
int vis[N], level[N];

void bfs(int src) {
    deque<int> q;
    q.push_back(src);
    vis[src] = 1;
    level[src] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        cout << v << ' ';
        for (auto c: graph[v]) {
            if (vis[c.first])
                continue;
            if (c.second == 0)
                q.push_front(c.first);
            else
                q.push_back(c.first);
            vis[c.first] = 1;
            level[c.first] = level[v] + c.second;
        }
    }
    cout << '\n';
}

int main() {
    int v, e;
    cin >> v >> e;
    for(int i=0; i<e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, 1});
    }
    bfs(1);
    return 0;
}