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
const int N = 2e5 + 10;
const int INF = 1e9;
const ll LINF = 1e17;

int n;
double dp[301][301][301];

double dfs(int i, int j, int k) {
    if (i==0 and j==0 and k == 0) return 0;
    if (i<0 or j<0 or k<0) return 0;
    if (dp[i][j][k] > -0.9) return dp[i][j][k];
    double ans = n + (dfs(i-1, j, k)*i) + (dfs(i+1, j-1, k)*j) + (dfs(i, j+1, k-1)*k);
    return dp[i][j][k] = ans/(i+j+k);
}

int main() {
    fast_io;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    int ones = 0, twos = 0, threes = 0;
    int j;
    rep(i, 0, n) {
        cin >> j;
        if (j == 1) ones++;
        else if (j == 2) twos++;
        else threes++;
    }
    dfs(ones, twos, threes);
    cout << fixed << setprecision(10) << dp[ones][twos][threes] << endl;
}