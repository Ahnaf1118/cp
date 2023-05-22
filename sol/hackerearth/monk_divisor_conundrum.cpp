// Monk and Divisor Conundrum
// partially accepted
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<ii> vii;
const int M = 1e9 + 7;
const int N = 1e5 + 10;

vll freq(N, 0);
vll ctn(N, 0);

int main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    for (int i=1; i<N; i++) {
        for (int j=i; j<N; j+=i) {
            ctn[i] += freq[j];
        }
    }
    int q; cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        ll ans = ctn[a] + ctn[b];
        ll lcm = a * 1LL * b / __gcd(a, b);
        if (lcm < N)
            ans -= ctn[lcm];
        cout << ans << endl;
    }
    return 0;
}