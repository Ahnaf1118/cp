#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> graph[N];
int depth[N];

void dfs(int v, int p = 0)
{
    for (int c : graph[v])
    {
        if (c == p)
            continue;
        depth[c] = depth[v] + 1;
        dfs(c, v);
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1, 0);
    int mx = INT_MIN;
    int mxi = 0;
    for (int i = 1; i <= v; i++)
    {
        if (depth[i] > mx)
        {
            mx = max(mx, depth[i]);
            mxi = i;
        }
        depth[i] = 0;
    }
    dfs(mxi, 0);
    mx = INT_MIN;
    for (int i = 1; i <= v; i++)
    {
        mx = max(mx, depth[i]);
    }
    cout << mx << endl;
    return 0;
}
