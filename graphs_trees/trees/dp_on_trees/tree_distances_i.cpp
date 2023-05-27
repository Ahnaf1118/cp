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
vi height(N, 0);
vi dist(N, 0);

void dfs(int v, int p) {
    for (auto c: graph[v]) {
        if (c==p) continue;
        dfs(c, v);
        height[v] = max(height[v], height[c] + 1);
    }
}

void solve(int v, int p, int par) {
    vi pre, suf;
    for (auto c: graph[v]) {
        if (c==p) continue;
        pre.pb(height[c]);
        suf.pb(height[c]);
    }
    for (int i=1; i<(int)pre.size(); i++)
        pre[i] = max(pre[i], pre[i-1]);
    for (int i=(int)suf.size()-2; i>=0; i--)
        suf[i] = max(suf[i], suf[i+1]);
    int index = 0;
    for (auto c: graph[v]) {
        if (c==p) continue;
        int op1 = (index==0)?-INF:pre[index-1];
        int op2 = (index==(int)suf.size()-1)?-INF:suf[index+1];
        solve(c, v, 1+max(par, max(op1, op2)));
        index++;
    }
    dist[v] = 1 + max(par, ((pre.empty())?-1:pre.back()));
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
    solve(1, 0, -1);
    rep(i, 1, n+1) cout << dist[i] << ' '; 
}