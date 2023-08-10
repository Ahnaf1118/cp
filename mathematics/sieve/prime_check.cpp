#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
const int M = 1e9 + 7;
const int N = 1e7 + 10;
vb is_prime(N, true);

void sieve(int n = N) {
    is_prime[0] = is_prime[1] = false;
    for (int i=2; i<=n; i++) {
        if (is_prime[i]) {
            for (int j= i*2; j<=n; j+=i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    sieve(N);
    for (int i=0; i<=100; i++)
        if (is_prime[i])
            cout << i << ' ';
    cout << endl;
    return 0;
}