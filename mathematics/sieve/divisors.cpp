#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
vi divisors[N];

void sieve(int n = N) {
    for (int i=2; i<n; i++) {
        for (int j=i; j<n; j+=i) {
            divisors[j].pb(i);
        }
    }
}

int main() {
    sieve(N);
    for (int i=1; i<=10; i++) {
        for (auto div: divisors[i]) {
            cout << div << ' ';
        }
        cout << '\n';
    }
    return 0;
}