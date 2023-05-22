#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int MODULO = 1e9 + 7;

bool prime_check(int n) {
    if (n==1)
        return false;
    for (int i=2; i<n; i++)
        if (n%i==0)
            return false;
    return true;
}

bool prime_check_SQRT(int n) {
    if (n==1)
        return false;
    for (int i=2; i<=sqrt(n); i++)
        if (n%i==0)
            return false;
    return true;
}

int main() {
    cout << prime_check_SQRT(67) << endl;
    return 0;
}