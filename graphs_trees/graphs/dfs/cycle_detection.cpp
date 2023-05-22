#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

bool dfs(int v, int p) {
    vis[v] = true;
    bool loop = false;
    for (int child: g[v]) {
        if (vis[child] && child == p) continue;
        if (vis[child])
            return true;
        loop |= dfs(child, v);
    }
    return loop;
}

int main() {
    int v, n;
    cin >> v >> n;
    for (int i=0; i<n; i++) {
        int v1, v2;
        cin >> v1 >> v1;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bool loop = false;
    for (int i=0; i<v; i++) {
        if (vis[i])
            continue;
        loop |= dfs(i, 0);
    }
    cout << loop << endl;
    return 0;
}