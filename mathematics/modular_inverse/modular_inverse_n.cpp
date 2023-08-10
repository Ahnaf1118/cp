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

int modInverse(int A, int M)
{
    for (int X = 1; X < M; X++)
        if (((A % M) * (X % M)) % M == 1)
            return X;
    return -1;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        cout << modInverse(n, M) << endl;
    }
    return 0;
}