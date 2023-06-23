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
const int INF = 1e9;
const ll LINF = 1e17;
 
int main() {
    fast_io;
    int n, k;
    cin >> n >> k;
    vll a(n, 0);
    rep(i, 0, n) cin >> a[i];
    vvll dp(n, vll(k+1, 0));
	for (int i=0; i<=a[0]; i++) dp[0][i] = 1;
	for (int i=1; i<n; i++) {
		vll pre(k+1, 0);
		pre[0] = dp[i-1][0];
		for (int j=1; j<=k; j++) pre[j] = (pre[j-1] + dp[i-1][j]) % M;
		for (int j=0; j<=k; j++) {
			if (j-a[i]>0) dp[i][j] = (pre[j] + M - pre[j-a[i]-1]) % M;
			else dp[i][j] = pre[j];
		}
	}
    cout << dp[n-1][k] << endl;
}
