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

bool dfs(int vertex, stack<int> &stk, vi &vis, vi &in, vi adj[]) {
    stk.push(vertex);
    vis[vertex] = in[vertex] = 1;
    for (auto child: adj[vertex]) {
        if (not vis[child]) {
            if (dfs(child, stk, vis, in, adj)) return true;
        }
        if (not in[child]) continue; 
        stk.push(child);
        return true;
    }
    in[vertex] = 0;
    stk.pop();
    return false;
}
 
int main() {
    fast_io;
    int n, m;
    cin >> n >> m;
    vi adj[n+1];
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    stack<int> stk;
    vi vis(n+1, 0), in(n+1, 0);
    bool res = false;
    for (int i=1; i<=n; i++) {
        if (vis[i]) continue;
        res = dfs(i, stk, vis, in, adj);
        if (res) break;
    }
    if (not res) return cout << "IMPOSSIBLE" << endl, 0;
    vi ans; int temp = stk.top();
    while (stk.size()) {
        ans.pb(stk.top()), stk.pop();
        if (ans.back() == temp and ans.size() > 1) break;
    }
    reverse(all(ans));
    cout << ans.size() << endl;
    for (auto it: ans) cout << it << ' ';
}
