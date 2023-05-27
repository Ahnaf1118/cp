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
vvi dp1(50010, vi(510, 0)), dp2(50010, vi(510, 0));

void dfs(int v, int p, int &k) {
    for (auto c: graph[v]) {
        if (c==p) continue;
        dfs(c, v, k);
    }
    dp1[v][0] = 1;
    for (int i=1; i<=k; i++) {
        for (auto c: graph[v]) {
            if (c==p) continue;
            dp1[v][i] += dp1[c][i-1];
        }
    }
}

void solve(int v, int p, int &k) {
    for (int i=0; i<=k; i++) dp2[v][i] = dp1[v][i];
    if (p) {
        dp2[v][1] += dp2[p][0];
        for (int i=2; i<=k; i++) {
            dp2[v][i] += dp2[p][i-1];
            dp2[v][i] -= dp1[v][i-2];
        }
    }
    for (auto c: graph[v]) {
        if (c==p) continue;
        solve(c, v, k);
    }
}

int main() {
    int n, k; cin >> n >> k;
    rep(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, 0, k);
    solve(1, 0, k);
    ll ans = 0;
    for (int i=1; i<=n; i++) ans += dp2[i][k];
    cout << ans/2;
}