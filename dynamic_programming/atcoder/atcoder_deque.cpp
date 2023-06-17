#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
#define rep(i, a, b) for (int i=a; i<b; i++)
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
const int M = 1e9 + 7;
const int N = 3e3 + 10;
const int INF = 1e9;
const ll LINF = 1e17;
 
vll a(N, 0);
vector<vll> dp(N, vll(N, -1));
 
ll dfs(int i, int j) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    ll ans = max(a[i] + min(dfs(i+2, j), dfs(i+1, j-1)), a[j] + min(dfs(i+1, j-1), dfs(i, j-2)));
    return dp[i][j] = ans;
}
 
int main() {
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];
    ll sum = accumulate(all(a), 0ll);
    cout << 2*dfs(0, n-1) - sum << endl;
}