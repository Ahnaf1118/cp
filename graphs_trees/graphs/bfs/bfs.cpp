#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];
int level[N];

void bfs(int v) {
    queue<int> q;
    q.push(v);
    vis[v] = true;
    while(!q.empty()) {
        int cv = q.front();
        q.pop();
        cout << cv << ' ';
        for(int c: graph[cv]) {
            if (vis[c])
                continue;
            q.push(c);
            vis[c] = true;
            level[c] = level[cv] + 1;
        }
    }
    cout << endl;
}

int main() {
    int v, e;
    cin >> v >> e;
    for(int i=0; i<e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bfs(1);
    for (int i=1; i<=v; i++) 
        cout << level[i] << ' ';
    cout << '\n';
    return 0;
}