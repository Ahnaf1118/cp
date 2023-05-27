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
    int n; cin >> n;
    vi a(n, 0);
    rep(i, 0, n) cin >> a[i];
    int m; cin >> m;
    vi b(m, 0);
    rep(i, 0, m) cin >> b[i];
    vi dp(m+1, 0);
    for (int i=0; i<n; i++) {
        int cur = 0;
        for (int j=0; j<m; j++) {
            if (a[i] == b[j]) {
                dp[j] = max(cur+1, dp[j]);
            }
            if (a[i] > b[j]) {
                cur = max(cur, dp[j]);
            }
        }
    }
    cout << *max_element(all(dp)) << endl;
}