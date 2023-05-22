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
const int N = 2e5 + 10;
const int INF = 1e9;
 
vii graph[N];
vi vis(N, 0);
vi dist(N, INT_MAX);
vi par(N, 0);

void dijkstra(int src) {
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while(pq.size() > 0) {
        int cur_v = pq.top().second;
        pq.pop();
        if (vis[cur_v])
            continue;
        vis[cur_v] = 1;
        for (auto child: graph[cur_v]) {
            int child_v = child.first;
            int child_w = child.second;
            if (dist[cur_v] + child_w < dist[child_v]) {
                dist[child_v] = dist[cur_v] + child_w;
                par[child_v] = cur_v;
                pq.push({dist[child_v], child_v});
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
    vi ans;
    int n = v;
    while(n != 0) {
        ans.pb(n);
        n = par[n];
    }
    reverse(all(ans));
    for (int a: ans) {
        cout << a << ' ';
    }
    return 0;
}