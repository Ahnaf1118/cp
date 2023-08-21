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
const ll LINF = 2e18;

int main() {
    fast_io;
    int n, k; cin >> n >> k;
    vi a(n); rep(i, 0, n) cin >> a[i];
    if (k == 1) {
        for (int i=0; i<n; i++) cout << a[i] << ' ';
        return 0;
    }
    if (k == 2) {
        for (int i=0; i<n-1; i++) cout << min(a[i], a[i+1]) << ' ';
        return 0;
    }
    multiset<int> lst, rst;
    vi b(a.begin(), a.begin()+k);
    sort(all(b));
    for (int i=0; i<k/2+(k%2); i++) lst.insert(b[i]);
    for (int i=k/2+(k%2); i<k; i++) rst.insert(b[i]);
    cout << *lst.rbegin() << ' ';
    for (int i=1; i<n-k+1; i++) {
        if (lst.find(a[i-1]) != lst.end()) lst.erase(lst.find(a[i-1]));
        else rst.erase(rst.find(a[i-1]));
        if (*lst.rbegin() < a[k-1+i]) rst.insert(a[k-1+i]);
        else lst.insert(a[k-1+i]);
        while (lst.sz < k/2+(k%2)) {
            auto it = *rst.begin();
            lst.insert(it);
            rst.erase(rst.find(it));
        }
        while (lst.sz > k/2+(k%2)) {
            auto it = *lst.rbegin();
            rst.insert(it);
            lst.erase(lst.find(it));
        }
        cout << *lst.rbegin() << ' ';
    }
}
