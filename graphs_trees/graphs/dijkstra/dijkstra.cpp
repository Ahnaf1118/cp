#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<pair<int, int>> graph[N];
vector<int> vis(N, 0);
vector<int> dist(N, INT_MAX);

void dijkstra(int src) {
    set<pair<int, int>> st;
    st.insert({0, src});
    dist[src] = 0;
    while(st.size() > 0) {
        auto cur = *st.begin();
        int cur_v = cur.second;
        int cur_wt = cur.first;
        st.erase(st.begin());
        if (vis[cur_v])
            continue;
        vis[cur_v] = 1;
        for (auto child: graph[cur_v]) {
            int child_v = child.first;
            int child_w = child.second;
            if (cur_wt + child_w < dist[child_v]) {
                dist[child_v] = cur_wt + child_w;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    for (int i=0; i<e; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
    }
    dijkstra(1);
    for (int i=1; i<=v; i++) {
        cout << i << ' ' << dist[i] << endl;
    }
    return 0;
}