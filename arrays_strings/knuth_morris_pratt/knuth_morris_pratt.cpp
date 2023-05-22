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
    string s, t;
    cin >> s >> t;
    int n=s.length(), m=t.length();
    vi pi(m, 0);
    int y=0, x=1;
    while(x<m) {
        if (t[x] == t[y]) {
            pi[x] = y+1;
            x++, y++;
        }
        else {
            if (y!=0) y = pi[y-1];
            else {
                pi[x] = 0; x++;
            }
        }
    }
    int i=0, j=0, cnt = 0;
    while(j<n) {
        if (s[j] == t[i]) j++, i++;
        else {
            if (i!=0) i = pi[i-1];
            else j++;
        }
        if (i==m) cnt++, i=pi[i-1];
    }
    cout << cnt << endl;
}