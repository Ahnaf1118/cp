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
typedef unsigned long long llu;
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

int dp[N][2]; int n;
vi a(N, 0);

int dfs(int index, int turn) {
    if (index >= n) return dp[index][turn] = 0;
    if (dp[index][turn] != -1) return dp[index][turn];
    if (!turn) return dp[index][turn] = min(dfs(index+1, turn^1), dfs(index+2, turn^1));
    else return dp[index][turn] = min(dfs(index+1, turn^1) + a[index], dfs(index+2, turn^1) + a[index] + a[index+1]);
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for (int i=0; i<n+10; i++) a[i] = 0;
        for (int i=0; i<n; i++) cin >> a[i];
        // memset(dp, -1, sizeof(dp));
        for (int i=0; i<=n; i++) dp[i][0] = dp[i][1] = -1;
        dfs(0, 1);
        cout << dp[0][1] << endl;
    }
}