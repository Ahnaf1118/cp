#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int MODULO = 1e9 + 7;

vi divisors(int n) {
    vi ans;
    for (int i=1; i<=n; i++) {
        if (n % i == 0)
            ans.pb(i);
    }
    return ans;
}

vi divisorsSQRT(int n) {
    vi ans;
    for (int i=1; i<=sqrt(n); i++) {
        if (n % i == 0) {
            ans.pb(i);
            if (n/i != i)
                ans.pb(n/i);
        }
    }
    return ans;
}

int main() {
    vi ans = divisorsSQRT(36);
    for (auto a: ans) {
        cout << a << ' ';
    }
    cout << '\n';
    return 0;
}