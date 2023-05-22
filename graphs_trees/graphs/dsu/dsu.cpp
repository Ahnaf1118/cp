#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> par(N, 0);
vector<int> size(N, 0);

void make(int v) {
    par[v] = v;
}

int find(int v) {
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}

void Union(int v1, int v2) {
    int p1 = find(v1);
    int p2 = find(v2);
    if (p1 == p2)
        return;
    if (size[p1] < size[p2])
        swap(p1, p2);
    par[p2] = p1;
    size[p1] += size[p2];
}

int main() {
    int v, e;
    cin >> v >> e;
    for (int i=1; i<=v; i++) {
        make(i);
    }
    for (int i=0; i<e; i++) {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }
    int cc = 0;
    for (int i=1; i<=v; i++) {
        if (i == par[i])
            cc++;
    }
    cout << cc << endl;
}