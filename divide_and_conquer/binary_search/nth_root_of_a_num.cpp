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

double multiply(double n, double m) {
    double ans = 1;
    for (int i=0; i<n; i++) {
        ans *= m;
    }
    return ans;
}

int main() {
    fast_io;
    int n, m;
    cin >> n >> m;
    double lo = 1, hi = m;
    while ((hi-lo) > 1e-6) {
        double md = (hi+lo) / 2.0;
        if (multiply(n, md) < m) lo = md;
        else hi = md;
    }
    cout << lo << endl;
}