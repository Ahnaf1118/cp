#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int MODULO = 1e9 + 7;

ll bin_multiplication(ll a, ll b, ll M) {
    a %= M;
    ll res = 0;
    while(b) {
        if (b&1) {
            res = (res+a) % M;
        }
        a = (a + a) % M;
        b >>= 1;
    }
    return res;
}

ll bin_exponentiation(ll a, ll b, ll M) {
    a %= M;
    ll res = 1;
    while(b) {
        if (b&1) {
            res = bin_multiplication(res, a, M);
        }
        a = bin_multiplication(a, a, M);
        b >>= 1;
    }
    return res;
}

int main() {
    cout << bin_exponentiation(50, bin_exponentiation(64, 32, MODULO-1), MODULO) << endl;
    return 0;
}