#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
#define B begin()
#define E end()
#define sz size()
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, a, b) for (int i=a; i<b; i++)
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
const int M = 998244353;
const int N = 2e5 + 10;
const int INF = 1e9;
const ll LINF = 1e17;

// ll a[N], tree[4*N];
// void build(int node, int start, int end) {
//     if (start == end) {
//         tree[node] = a[start];
//         return;
//     }
//     int mid = (start+end)>>1;
//     build(2*node, start, mid);
//     build(2*node+1, mid+1, end);
//     tree[node] = min(tree[2*node], tree[2*node+1]);
// }
// ll query(int node, int start, int end, int left, int right) {
//     if (start > right or end < left) return INF;
//     if (start >= left and end <= right) return tree[node];
//     int mid = (start+end) >> 1;
//     return min(query(2*node, start, mid, left, right), query(2*node+1, mid+1, end, left, right));
// }
// void update(int node, int start, int end, int index, int val) {
//     if (start == end) {
//         a[start] = val, tree[node] = val;
//         return;
//     }
//     int mid = (start+end) >> 1;
//     if (index <= mid) update(2*node, start, mid, index, val);
//     else update(2*node+1, mid+1, end, index, val);
//     tree[node] = min(tree[2*node], tree[2*node+1]);
// }

ii a[N], tree[4*N];
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) >> 1;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    if (tree[2*node].F < tree[2*node+1].F) {
        tree[node] = tree[2*node];
    } else if (tree[2*node].F > tree[2*node+1].F) {
        tree[node] = tree[2*node+1];
    } else {
        tree[node] = {tree[2*node].F, tree[2*node].S + tree[2*node+1].S};
    }
}
ii query(int node, int start, int end, int left, int right) {
    if (start > right or end < left) return {INF, -1};
    if (start >= left and end <= right) return tree[node];
    int mid = (start + end) >> 1;
    ii q1 = query(2*node, start, mid, left, right), q2 = query(2*node+1, mid+1, end, left, right);
    if (q1.F < q2.F) return q1;
    if (q2.F < q1.F) return q2;
    return {q1.F, q1.S + q2.S};
}
void update(int node, int start, int end, int index, int val) {
    if (start == end) {
        a[index] = tree[node] = {val, 1};
        return;
    }
    int mid = (start + end) >> 1;
    if (index <= mid) update(2*node, start, mid, index, val);
    else update(2*node+1, mid+1, end, index, val);
    if (tree[2*node].F < tree[2*node+1].F) {
        tree[node] = tree[2*node];
    } else if (tree[2*node].F > tree[2*node+1].F) {
        tree[node] = tree[2*node+1];
    } else {
        tree[node] = {tree[2*node].F, tree[2*node].S + tree[2*node+1].S};
    }
}

int main() {
    fast_io;
    int n, m; cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i].F, a[i].S = 1;
    build(1, 0, n-1);
    while (m--) {
        // for (int i=0; i<n; i++) cout << a[i] << ' '; cout << endl;
        int x, l, r;
        cin >> x >> l >> r;
        if (x == 1) {
            update(1, 0, n-1, l, r);
        }
        else {
            ii res = query(1, 0, n-1, l, r-1);
            cout << res.F << ' ' << res.S << endl;
        }
    }
}