#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int M = 1e9 + 7;

ll power_recursive(ll a, ll b) {
    if (b == 1)
        return a;
    ll res = power_recursive(a, b/2);
    if (b & 1)
        return a * res * res;
    return res * res;
}

ll power_iterative(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b&1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    cout << power_recursive(3, 13) << endl;
    cout << power_iterative(3, 13) << endl;
    cout << (ll)pow(3, 13) << endl;
    return 0;
}