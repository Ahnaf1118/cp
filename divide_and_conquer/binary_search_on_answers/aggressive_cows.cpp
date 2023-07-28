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

bool check(int md, int c, int n, vi &a) {
    int cnt = 1, cur = 0, start = a[0];
    if (c > n) return false;
    for (int i=1; i<n; i++) {
        if (a[i]-start >= md) {
            start = a[i];
            cnt++;
        }
    }
    return cnt >= c;
}

int main() {
    fast_io;
    int t; cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        vi a(n, 0);
        rep(i, 0, n) cin >> a[i];
        sort(all(a));
        int lo = 0, hi = a[n-1]-a[0];
        int res = -1;
        while (lo <= hi) {
            int md = (lo+hi)>>1;
            if (check(md, c, n, a)) res=md, lo=md+1;
            else hi=md-1;
        }
        cout << res << endl;
    }
}
