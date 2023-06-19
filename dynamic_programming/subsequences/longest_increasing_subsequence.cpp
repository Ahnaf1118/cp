#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e9;

vi dp(N, 1);

int get_comb(map<int, int> &combs, int num) {
    auto it = combs.lower_bound(num);
    if (it == combs.begin())
        return 0;
    it--;
    return it->second;
}

void insert(map<int, int> &combs, int num, int adv) {
    if (combs[num] >= adv)
        return;
    combs[num] = adv;
    auto it = combs.find(num);
    it++;
    while(it != combs.end() && it->second <= adv) {
        auto temp = it;
        it++;
        combs.erase(temp);
    }
}

int main() {
    int n; cin >> n;
    vi nums(n, 0);
    for (int i=0; i<n; i++) {
        cin >> nums[i];
    }
    map<int, int> combs;
    dp[0] = 1;
    combs[nums[0]] = dp[0];
    for (int i=1; i<n; i++) {
        dp[i] = 1 + get_comb(combs, nums[i]);
        insert(combs, nums[i], dp[i]);
    }
    cout << dp[n-1] << endl;
    return 0;
}