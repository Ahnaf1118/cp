#include <bits/stdc++.h>
using namespace std;
#define VISITED true
const int N = 1e5 + 10;

vector<int> graph[N];
bool vis[N] = {0};

void dfs(int vertex) {
    vis[vertex] = VISITED;
    cout << vertex << ' ';
    for (int child: graph[vertex]) {
        if (vis[child])
            continue;
        dfs(child);
    }
}

int main() {
    int v, n;
    cin >> v >> n;
    for (int i=0; i<n; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    cout << '\n';
    return 0;
}