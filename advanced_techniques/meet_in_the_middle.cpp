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

void dfs(int index, int sum, int n, vector<int> &arr, vi &subsets) {
    if (index == n) subsets.pb(sum);
    else {
    dfs(index+1, sum, n, arr, subsets);
    dfs(index+1, sum+arr[index], n, arr, subsets);
    }
}

int main() {
    fast_io;
    int n, a, b;
    cin >> n >> a >> b;
    vi arr(n, 0);
    rep(i, 0, n) cin >> arr[i];
    vi subsets1, subsets2;
    dfs(0, 0, n/2, arr, subsets1);
    dfs(n/2, 0, n, arr, subsets2);
    sort(all(subsets2));
    ll cnt = 0;
    for (auto i: subsets1) {
        auto hi = upper_bound(all(subsets2), b-i)-subsets2.begin();
        auto lo = lower_bound(all(subsets2), a-i)-subsets2.begin();
        cnt += (hi-lo);
    }
    cout << cnt << endl;
}
