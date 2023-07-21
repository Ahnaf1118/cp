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
const int N = 1e6 + 10;
const int INF = 2e9;
const ll LINF = 1e17;

vs dfs(int n) {
    vs res;
    if (n == 1) {
        res.pb("0");
        res.pb("1");
        return res;
    }
    vs temp = dfs(n-1);
    for (int i=0; i<temp.size(); i++) res.pb('0'+temp[i]);
    for (int i=temp.size()-1; i>=0; i--) res.pb('1'+temp[i]);
    return res;
}

int main() {
    fast_io;
    int n; cin >> n;
    vs  res = dfs(n);
    for (auto &r: res) cout << r << endl;
}
