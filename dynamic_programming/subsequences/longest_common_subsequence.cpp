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
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    vvi dp(n+1, vi(m+1, 0)), dir(n+1, vi(m+1, 0));
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            if (i==0) dp[i][j] = j;
            else if (j==0) dp[i][j] = i;
            else if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1], dir[i][j] = 1;
            else {
                if (dp[i-1][j] < dp[i][j-1]) dp[i][j] = dp[i-1][j]+1, dir[i][j] = 2;
                else dp[i][j] = dp[i][j-1]+1, dir[i][j] = 3;
            }
        }
    }
    string res = "";
    int i = n, j = m;
    while(i>=0 and j>=0 and dir[i][j]) {
        if (dir[i][j] == 1) res.pb(a[i-1]), i--, j--;
        else if (dir[i][j] == 2) i--;
        else j--;
    }
    reverse(all(res));
    cout << res << endl;
}