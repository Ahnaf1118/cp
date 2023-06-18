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

int main() {
    fast_io;
    int n, k; cin >> n >> k;
    vi a(n, 0), b(n, 0);
    for (int i=0; i<n; i++) cin >> a[i] >> b[i];
    vector<vll> dp(n+1, vll(k+1, 0));
    dp[0][a[0]] = b[0];
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - a[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-a[i]] + 0ll + b[i]);
        }
    }
    cout << *max_element(all(dp[n])) << endl;
}