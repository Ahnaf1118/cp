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
    int n, m;
    cin >> n >> m;
    vector<pair<int, double>> adj[n+1];
    for (int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].pb({v, wt});
    }
    vd dist(n+1, DBL_MAX);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    dist[1] = 0;
    pq.push({dist[1], 1});
    while (pq.size()) {
        auto qr = pq.top(); pq.pop();
        int vertex = qr.second;
        double cost = qr.first;
        if (cost > dist[vertex]) continue;
        for (auto pr: adj[vertex]) {
            int ch = pr.first;
            double wt = pr.second;
            if (dist[vertex] + 0.0 + wt > dist[ch]) continue;
            dist[ch] = dist[vertex] + 0.0 + wt;
            pq.push({dist[ch], ch});
        }
    }
    for (int i=1; i<=n; i++) cout << (ll)round(dist[i]) << ' ';
}
