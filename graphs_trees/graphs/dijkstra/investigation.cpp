#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
#define sz size()
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, a, b) for (int i=a; i<b; i++)
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 2e9;
const ll LINF = 2e17;
 
int main() {
    fast_io;
    int n, m;
    cin >> n >> m;
    vii adj[n+1];
    for (int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].pb({v, wt});
    }
    vll dist(n+1, LINF), cnt(n+1, 0), mn(n+1, INF), mx(n+1, 0);
    dist[1] = mn[1] = mx[1] = 0;
    cnt[1] = 1;
    priority_queue<vll, vector<vll>, greater<vll>> pq;
    pq.push({dist[1], 1});
    while (pq.sz) {
        auto vec = pq.top(); pq.pop();
        ll cost = vec[0], vertex = vec[1];
        if (cost > dist[vertex]) continue;
        for (auto pr: adj[vertex]) {
            int child = pr.F, weight = pr.S;
            ll distance = cost + 0ll + weight;
            if (distance > dist[child]) continue;
            if (distance == dist[child]) {
                cnt[child] = (cnt[child] + 0ll + cnt[vertex]) % M;
                mn[child] = min(mn[child], mn[vertex] + 1);
                mx[child] = max(mx[child], mx[vertex] + 1);
                continue;
            }
            cnt[child] = cnt[vertex];
            mn[child] = mn[vertex] + 1;
            mx[child] = mx[vertex] + 1;
            dist[child] = distance;
            pq.push({dist[child], child});
        }
    }
    cout << dist[n] << ' ' << cnt[n] << ' ' << mn[n] << ' ' << mx[n] << endl;
}
