#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<pair<int, int>> graph[N];
vector<int> level(N, INT_MAX);

int bfs(int src, int n)
{
    deque<int> q;
    q.push_back(src);
    level[src] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for (auto c : graph[v])
        {
            int cv = c.first;
            int cw = c.second;
            if (level[v] + cw < level[cv])
            {
                level[cv] = level[v] + cw;
                if (cw == 0)
                    q.push_front(cv);
                else
                    q.push_back(cv);
            }
        }
    }
    return level[n] == INT_MAX? -1: level[n];
}

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
            continue;
        graph[x].push_back({y, 0});
        graph[y].push_back({x, 1});
    }
    cout << bfs(1, v);
    return 0;
}