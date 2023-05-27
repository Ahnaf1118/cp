#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
#define rep(i, a, b) for (int i=a; i<b; i++)
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
vll sz(N, 1ll), sa(N, 0ll), dp(N, 0ll);

void dfs(int v, int p) {
    for (auto c: graph[v]) {
        if (c==p) continue;
        dfs(c, v);
        sz[v] += sz[c];
        sa[v] += sz[c] + sa[c];
    }
}

void solve(int v, int p, ll par_ans, int n) {
    dp[v] = sa[v] + par_ans + n - sz[v];
    for (auto c: graph[v]) {
        if (c==p) continue;
        solve(c, v, dp[v] - sa[c] - sz[c], n);
    } 
}

int main() {
    int n; cin >> n;
    rep(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, 0);
    solve(1, 0, 0, n);
    rep(i, 1, n+1) cout << dp[i] << ' '; 
}