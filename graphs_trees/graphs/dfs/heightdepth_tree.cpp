#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];
int depth[N], height[N];

void dfs(int v, int p) {
    vis[v] = true;
    for (int child: graph[v]) {
        if (vis[child])
            continue;
        depth[child] = depth[v] + 1;
        dfs(child, v);
        height[v] = max(height[v], height[child] + 1);
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    for (int i=0; i<e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v2);
    }
    dfs(1, 0);
    for (int i=1; i<=v; i++) {
        cout << height[i] << ' ' << depth[i] << '\n';
    }
    cout << '\n';
    return 0;
}