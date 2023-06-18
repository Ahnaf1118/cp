#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e9;
 
ll dp[N];
map<int, ll> mp;
 
ll get_comb(int start) {
    auto it = mp.lower_bound(start);
    if (it == mp.begin())
        return 0;
    it--;
    return it->second;
}
 
void insert(int end, ll price) {
    if (mp[end] >= price)
        return;
    mp[end] = price;
    auto it = mp.find(end);
    while(it != mp.end() && it->second < price) {
        auto temp = it;
        it++;
        mp.erase(temp);
    }
    auto cur = mp.find(end);
    it = mp.find(end);
    it--;
    while(it != mp.begin() && it->second >= cur->second) {
        it--;
        auto temp = cur;
        cur--;
        mp.erase(temp);
    }
    if (it->second > cur->second) {
        mp.erase(cur);
    }
}
 
ll solve(viii &projects) {
    for (int index = 1; index < projects.size(); index++) {
        int start = projects[index].second.first;
        int end = projects[index].first;
        int price = projects[index].second.second;
        dp[index] = price + get_comb(start);
        insert(end, dp[index]);
    }
    return *max_element(dp, dp + projects.size());
}
 
int main() {
    memset(dp, 0, sizeof(dp));
    int n; cin >> n;
    viii projects = {{0, {0, 0}}};
    for (int i=0; i<n; i++) {
        int s, e, p;
        cin >> s >> e >> p;
        projects.pb({e, {s, p}});
    }
    sort(all(projects));
    cout << solve(projects) << endl;
    return 0;
}