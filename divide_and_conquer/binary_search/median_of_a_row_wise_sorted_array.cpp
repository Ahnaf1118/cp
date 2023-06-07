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

int count_occurences(int num, vvi &a) {
    int cnt = 0;
    for (auto row: a) {
        cnt += distance(row.begin(), upper_bound(all(row), num));
    }
    return cnt;
}

int main() {
    fast_io;
    int n; cin >> n;
    vvi a(n, vi(n, 0));
    for (int i=0; i<n; i++) 
        for (int j=0; j<n; j++) 
            cin >> a[i][j];
    int lo = 0, hi = N;
    while(lo <= hi) {
        int md = (lo+hi) / 2;
        if (count_occurences(md, a) > floor((n*n)/2)) hi = md-1;
        else lo = md+1;
    }
    cout << lo << endl;
}