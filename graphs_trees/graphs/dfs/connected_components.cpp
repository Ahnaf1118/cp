#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];

vector<vector<int>> ccs;
vector<int> cc;

void dfs(int v)
{
    if (vis[v])
        return;
    vis[v] = true;
    cc.push_back(v);
    for (int child : graph[v])
    {
        dfs(child);
    }
}

int main()
{
    int v, n;
    cin >> v >> n;
    for (int i = 0; i < n; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for (int i = 1; i <= v; i++)
    {
        if (vis[i])
            continue;
        cc.clear();
        dfs(i);
        ccs.push_back(cc);
    }
    cout << ccs.size() << '\n';
    for (auto cce : ccs)
    {
        for (auto c : cce)
        {
            cout << c << ' ';
        }
        cout << '\n';
    }
    return 0;
}