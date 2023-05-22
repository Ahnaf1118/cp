#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int ss[N], ec[N];

void dfs(int v, int p=0) {
    ss[v] += v;
    if (v%2==0)
        ec[v]++;
    for (int c: graph[v]) {
        if (c == p)
            continue;
        dfs(c, v);
        ss[v] += ss[c];
        ec[v] += ec[c];
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    for (int i=0; i<e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1, 0);
    cout << '\n';
    for (int i=1; i<=v; i++) {
        cout << i << '\t' << ec[i] << '\t' << ss[i] << '\n';
    }
}