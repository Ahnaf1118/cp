// hackerearth unlock the door
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
long long fact[N];
int binExp(int a, int b, int m = M) {
	a %= m;
	int res = 1;
	while(b > 0) {
		if (b & 1) {
			res = (res * 1ll * a) % m;
		}
		a = (a * 1ll * a) % m;
		b >>= 1;
	}
	return res;
}
int main() {
	fact[0] = 1;
	for (int i=1; i<N; i++) {
		fact[i] = (fact[i-1] * 1ll * i) % M;
	}
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> b >> a;
		int num = fact[a] % M;
		int den = fact[a-b] % M;
		int ans = (num * 1ll * (binExp(den, M-2, M))) % M;
		cout << ans << endl;
	}	
}