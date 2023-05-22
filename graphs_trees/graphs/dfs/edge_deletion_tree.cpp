// delete an edge to get 2 trees such that product of their ss will be maximum. 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int ss[N];

void dfs(int v, int p = 0) {
    ss[v] += v;
    for(int c: graph[v]) {
        if (c == p)
            continue;
        dfs(c, v);
        ss[v] += ss[c];
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
    dfs(1);
    int mx = INT_MIN, temp = 0;
    for (int i=1; i<=v; i++) {
        cout << ss[i] << ' ';
        temp = ss[i] * (ss[1] - ss[i]);
        mx = max(mx, temp);
    }
    cout << endl;
    cout << mx << endl;
    return 0;
}