#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int sz = 2e5+10;
vi graph[sz], ans(sz, 0);

int dfs(int v, int p, int lvl) {
    int sum = 1;
    for (int c: graph[v]) {
        if (c == p)
            continue;
        sum += dfs(c, v, lvl + 1);
    }
    ans[v] = sum - lvl;
    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, 0, 1);
    sort(ans.begin() + 1, ans.begin() + n + 1);
    int sum = 0;
    for(int i = 1; i <= k; i++)
        sum += ans[i];
 
    cout << -sum << endl;
    return 0;
}