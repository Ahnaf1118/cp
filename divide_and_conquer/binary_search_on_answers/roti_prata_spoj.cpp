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
    int cnt = 0;
    for (int i=0; i<n; i++) {
        int cur = a[i], time = a[i];
        while (time <= md) {
            cnt++;
            cur += a[i];
            time += cur;
        }
    }
    return cnt >= c;
}

int main() {
    fast_io;
    int t; cin >> t;
    while (t--) {
        int c, n;
        cin >> c >> n;
        vi a(n, 0);
        for (int i=0; i<n; i++) cin >> a[i];
        int lo=1, hi=INF, res=-1;
        while (lo <= hi) {
            int md = (lo+hi) >> 1;
            if (check(md, c, n, a)) res=md, hi=md-1;
            else lo=md+1;
        }
        cout << res << endl;
    }
}
