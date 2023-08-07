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
const ll LINF = 1e17;

int dfs(int index, int turn, vi &a, vi &b, map<pair<int, int>, int> &mp) {
    if (index < 0) return 0;
    pair<int, int> hash = {index, turn};
    if (mp.find(hash) != mp.end()) return mp[hash];
    int mx = -INF;
    if (turn == 0) {
        mx = max(mx, dfs(index-1, turn, a, b, mp) + a[index]);
        int it = lower_bound(all(b), a[index]) - b.begin();
        if (b[it] == a[index]) {
            mx = max(mx, dfs(it-1, turn^1, a, b, mp) + a[index]);
        }
    } 
    else {
        mx = max(mx, dfs(index-1, turn, a, b, mp) + b[index]);
        int it = lower_bound(all(a), b[index]) - a.begin();
        if (a[it] == b[index]) {
            mx = max(mx, dfs(it-1, turn^1, a, b, mp) + b[index]);
        }
    }
    return mp[hash] = mx;
}

int main() {
    fast_io;
    while (1) {
        int n; cin >> n;
        if (n==0) break;
        vi a(n, 0);
        rep (i, 0, n) cin >> a[i];
        int m; cin >> m;
        vi b(m, 0);
        rep (i, 0, m) cin >> b[i];
        a.pb(INF), b.pb(INF);
        map<pair<int, int>, int> mp;
        cout << max(dfs(n-1, 0, a, b, mp), dfs(m-1, 1, a, b, mp)) << endl;
    }
}
