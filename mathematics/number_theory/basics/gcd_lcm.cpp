#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int M = 1e9 + 7;

int gcd(int a, int b) {
    if (a % b == 0)
        return b;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a*b)/gcd(a, b);
}

int main() {
    cout << __gcd(12, 18) << endl;
    cout << lcm(12, 9) << endl;
    return 0;
}