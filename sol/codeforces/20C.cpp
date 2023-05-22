// mle
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+3;
vector<pair<int, int>> graph[N];
bitset<N> vis;

void dijkstra(int src, vector<int> &dist, vector<int> &par) {
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
        for (auto &child: graph[cur_v]) {
            int child_v = child.first;
            int child_w = child.second;
            if (cur_wt + child_w < dist[child_v]) {
                par[child_v] = cur_v;
                dist[child_v] = cur_wt + child_w;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    graph->resize(v+2);
    vector<int> dist(v+1, INT_MAX);
    vector<int> par(v+1, -1);
    for (int i=0; i<e; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
        graph[y].push_back({x, wt});
    }
    par[1] = -1;
    dijkstra(1, dist, par);
    vector<int> res; 
    for (int u = v; u!=-1; u=par[u])
        res.push_back(u);
    reverse(res.begin(), res.end());
    if (res.size()<=1)
        cout << -1;
    else
        for (auto &ele: res) {
            cout << ele << ' ';
        }
    cout << endl;
    return 0;
}