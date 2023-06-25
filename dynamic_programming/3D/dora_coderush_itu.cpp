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
typedef vector<vll> vvll;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 2e9;
const ll LINF = 1e17;

vector<vvi> dp(1005, vvi(1005, vi(2, -1)));

int dfs(int index, int k, int turn, int m, int l, int r, vi &a, vi &b) {
    if (index >= m) return (k==0)?0:INF;
    if (dp[index][k][turn] != -1) return dp[index][k][turn];
    int same = 0, diff = 0;
    if (turn == 0) same = a[index], diff = b[index];
    else same = b[index], diff = a[index];
    int mn = INF;
    if (k>0) mn = min(mn, same + dfs(index+1, k-1, turn, m, l, r, a, b));
    else if (k==0) {
        for (int i=l; i<=r; i++) {
            mn = min(mn, diff + dfs(index+1, i-1, turn^1, m, l, r, a, b));
        }
    }
    return dp[index][k][turn] = mn;
}
 
int main() {
    fast_io;
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    vs a(n, "");
    for (int i=0; i<n; i++) cin >> a[i];
    vi x(m, 0), y(m, 0);
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            x[i] += (a[j][i]=='+');
            y[i] += (a[j][i]=='!');
        }
    }
    int mn = INF;
    for (int i=l; i<=r; i++) {
        mn = min(mn, dfs(0, i, 0, m, l, r, x, y));
        mn = min(mn, dfs(0, i, 1, m, l, r, x, y));
    }
    cout << mn << endl;
}