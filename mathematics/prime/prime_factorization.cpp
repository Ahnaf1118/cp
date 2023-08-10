#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int MODULO = 1e9 + 7;

vi prime_factors(int n) {
    if (n==1)
        return {};
    vi factors = {};
    for (int i=2; i<=n; i++)
        while (n % i == 0) {
            factors.pb(i);
            n /= i;
        }
    return factors;
}

vi prime_factors_SQRT(int n) {
    if (n==1)
        return {};
    vi factors = {};
    for (int i=2; i<=sqrt(n); i++)
        while (n % i == 0) {
            factors.pb(i);
            n /= i;
        }
    if (n > 1) {
        factors.pb(n);
    }
    return factors;
}

int main() {
    vi factors = prime_factors_SQRT(1140);
    for (auto factor: factors) {
        cout << factor << ' ';
    }
    cout << '\n';
    return 0;
}