#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
#define sz size()
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
const ll LINF = 2e17;

bool cmp(ii &a, ii& b) {
    if (a.F == b.F) return a.S > b.S;
    return a.F < b.F;
}
 
int main() {
    fast_io;
    int n; cin >> n;
    vii a(n);
    map<ii, int> contains, contained;
    for (int i=0; i<n; i++) cin >> a[i].F >> a[i].S;
    vii b = a;
    sort(all(a), cmp);
    int mx = 0;
    for (int i=0; i<n; i++) {
        contained[a[i]] = (a[i].S <= mx); 
        mx = max(mx, a[i].S);
    }
    int mn = INF;
    for (int i=n-1; i>=0; i--) {
        contains[a[i]] = (a[i].S >= mn); 
        mn = min(mn, a[i].S);
    }
    for (auto it: b) cout << contains[it] << ' ';
    cout << endl;
    for (auto it: b) cout << contained[it] << ' ';
    cout << endl;
}
