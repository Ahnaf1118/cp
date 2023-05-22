#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int par[N];

void dfs(int v, int p = 0) {
    par[v] = p;
    for (int c: graph[v]) {
        if (c == p)
            continue;
        dfs(c, v);
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    for(int i=0; i<e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    int l, r;
    cin >> l >> r;
    vector<int> lp;
    vector<int> rp;
    while(l != 0) {
        lp.push_back(l);
        l = par[l];
    }
    while(r != 0) {
        rp.push_back(r);
        r = par[r];
    }
    reverse(lp.begin(), lp.end());
    reverse(rp.begin(), rp.end());
    int minl = min(lp.size(), rp.size());
    int res = 0;
    for (int i=0; i<minl; i++) {
        if (lp[i] == rp[i]) {
            res = lp[i];
        }
        else{
            break;
        }
    }
    cout << res << '\n';
    return 0;
}