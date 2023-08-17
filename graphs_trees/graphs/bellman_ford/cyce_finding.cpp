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
    vvi edges;
    vll dist(n+1, 0);
    for (int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.pb({u, v, wt});
    }
    map<int, int> mp; int x;
    for (int i=0; i<n; i++) {
        x = -1;
        for (auto edge: edges) {
            int u=edge[0], v=edge[1], wt=edge[2];
            if (dist[u] + wt >= dist[v]) continue;
            dist[v] = dist[u] + wt;
            mp[v] = u, x = v;
        }
    }
    if (x == -1) return cout << "NO" << endl, 0;
    for (int i=0; i<n; i++) x = mp[x];
    vi res = {x}; x = mp[x];
    while (x != res[0]) res.pb(x), x = mp[x];
    res.pb(x);
    reverse(all(res));
    cout << "YES" << endl;
    for (auto it: res) cout << it << ' ';
    cout << endl;
}
