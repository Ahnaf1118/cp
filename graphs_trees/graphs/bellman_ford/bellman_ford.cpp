#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
const int M = 1e9 + 7;
const int N = 1e4;
const int INF = 1e9;
const ll LINF = 1e17;

viii edges;
vll dist(N, LINF);

void bellman_ford(int n) {
    for (int i=1; i<n; i++) {
        for (auto edge: edges) {
            int u = edge.first;
            int v = edge.second.first;
            int w = edge.second.second;
            if (dist[u] == LINF) continue;
            dist[v] = min(dist[v], dist[u] + w);
            dist[v] = max(dist[v], LINF*(-1));
        }
    }
}

void bellman_ford_neg(int n) {
    for (int i=1; i<n; i++) {
        for (auto edge: edges) {
            int u = edge.first;
            int v = edge.second.first;
            int w = edge.second.second;
            if (dist[u] == LINF) continue;
            dist[v] = max(dist[v], LINF*(-1));
            if (dist[u] + w < dist[v]) dist[v] = LINF*(-1);
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    for (int i=0; i<e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.pb({x, {y, -w}});
    }
    dist[1] = 0;
    bellman_ford(v);
    bellman_ford_neg(v);
    if (dist[v] == LINF*(-1)) cout << -1 << endl;
    else cout << dist[v]*(-1) << endl;
}