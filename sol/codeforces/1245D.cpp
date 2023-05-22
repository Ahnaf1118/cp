#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+10;
int par[N];
int sz[N];

void make(int v) {
    par[v] = v;
    sz[v] = 1;
}

int find(int v) {
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}

void Union(int u, int v) {
    int up = find(u);
    int vp = find(v);
    if (up == vp)
        return;
    if (up > vp)
        swap(up, vp);
    par[vp] = up;
    sz[up] += sz[vp];
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> cities(n+1);
    for (int i=1; i<=n; i++) {
        cin >> cities[i].first >> cities[i].second;
    }
    vector<long long> cs(n+1), ks(n+1);
    for (int i=1; i<=n; i++)
        cin >> cs[i]; 
    for (int i=1; i<=n; i++)
        cin >> ks[i]; 
    
    vector<pair<long long, pair<int, int>>> edges;
    for (int i=1; i<=n; i++) {
        edges.push_back({cs[i], {0, i}});
    } 
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int dist = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
            long long cost = dist * 1ll * (ks[i] + ks[j]);
            edges.push_back({cost, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());
    for (int i=1; i<=n; i++)
        make(i);
    long long t_wt = 0;
    vector<int> stations;
    vector<pair<int, int>> connections;
    for (auto edge: edges) {
        long long wt = edge.first;
        int x = edge.second.first;
        int y = edge.second.second;
        if (find(x) == find(y))
            continue;
        Union(x, y);
        t_wt += wt;
        if (x == 0 || y == 0)
            stations.push_back(max(x, y));
        else 
            connections.push_back({x, y});
        
    }
    cout << t_wt << endl;
    cout << stations.size() << endl;
    for (auto station: stations)
        cout << station << ' ';
    cout << endl << connections.size() << endl;
    for (auto connection: connections)
        cout << connection.first << ' ' << connection.second << endl;
    return 0;
}