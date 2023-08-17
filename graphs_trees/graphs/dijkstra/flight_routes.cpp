#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
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
    int n, m, k;
    cin >> n >> m >> k;
    vvll dist(n+1, vll(k+1, LINF));
    vii adj[n+1];
    for (int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].pb({v, wt});
    }
    for (int i=0; i<k; i++) dist[1][k] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while (pq.size()) {
        auto pr = pq.top(); pq.pop();
        ll cost = pr.F, vertex = pr.S;
        if (cost > dist[vertex][k-1]) continue;
        for (auto qr: adj[vertex]) {
            int child = qr.F, wt = qr.S;
            if (cost + wt >= dist[child][k-1]) continue;
            dist[child][k-1] = cost + 0ll + wt;
            pq.push({dist[child][k-1], child});
            sort(all(dist[child]));
        }
    }
    for (int i=0; i<k; i++) cout << dist[n][i] << ' ';
}