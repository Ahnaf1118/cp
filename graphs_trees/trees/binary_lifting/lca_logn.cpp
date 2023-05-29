#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
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
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e9;
const ll LINF = 1e17;

vi graph[N];
vi depth(N, 0);
vvi up(N, vi(20, 0));

void dfs(int v, int p) {
    up[v][0] = p;
    for (int i=1; i<20; i++)
        if (up[v][i-1] != -1) up[v][i] = up[up[v][i-1]][i-1];
        else up[v][i] = -1;
    for (auto c: graph[v]) {
        if (c==p) continue;
        depth[c] = depth[v]+1;
        dfs(c, v);
    }
}

int ans_query(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for (int i=19; i>=0; i--) {
        if (k >= (1<<i) and up[u][i] != -1) u = up[u][i], k -= (1<<i);
    }
    if (u == v) return u;
    for (int i=19; i>=0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main() {
    int n, q; cin >> n >> q;
    rep(i, 0, n-1) {
        int u=i+2, v;
        cin >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, -1);
    rep(i, 0, q) {
        int u, v;
        cin >> u >> v;
        cout << ans_query(u, v) << endl;
    }
}