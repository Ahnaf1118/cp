#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool cat[N];
int cn = 0;

int dfs(int v, int p, int m) {
    if (cat[v]) 
        m--;
    else 
        m = cn;
    if (m < 0) {
        return 0;
    }
    if (graph[v].size()==1) {
        return 1;
    }
    int cnt = 0;
    for(int c: graph[v]) {
        if (c == p)
            continue;
        cnt += dfs(c, v, m);
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int t;
        cin >> t;
        cat[i+1] = t;
    }
    cn = m;
    for(int i=0; i<n-1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    graph[1].push_back(0);
    cout << dfs(1, 0, m) << endl;
    return 0;
}