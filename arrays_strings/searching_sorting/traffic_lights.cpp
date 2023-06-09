#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
#define rep(i, a, b) for (int i=a; i<b; i++)
typedef long long ll;
typedef unsigned long long llu;
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
    int n, m;
    cin >> n >> m;
    multiset<int> lengths;
    set<int> positions;
    lengths.insert(n);
    positions.insert(0); positions.insert(n);
    for (int i=0; i<m; i++) {
        int a; cin >> a;
        positions.insert(a);
        auto it = positions.find(a);
        int pre = *prev(it), nxt = *next(it);
        lengths.erase(lengths.find(nxt - pre));
        lengths.insert(a - pre); lengths.insert(nxt - a);
        cout << *lengths.rbegin() << ' ';
    }
}