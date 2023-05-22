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

vi fact(N, 1);

int binExp(int a, int b, int m = M)
{
    a %= m;
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b >>= 1;
    }
    return result;
}

int main()
{
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * 1ll * i) % M;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int n, k;
        cin >> n >> k;
        int num = fact[n] % M;
        int den = (fact[n - k] * 1ll * fact[k]) % M;
        int ans = (num * 1ll * binExp(den, M - 2, M)) % M;
        cout << ans << endl;
    }
    return 0;
}