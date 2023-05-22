// network delay
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dijkstra(int src, int N, vector<vector<int>> &times) {
        vector<pair<int, int>> graph[N+10];
        for (auto time: times) {
            graph[time[0]].push_back({time[1], time[2]});
        }
        vector<int> vis(N+10, 0);
        vector<int> dist(N+10, INT_MAX);
        set<pair<int, int>> st;
        st.insert({0, src});
        dist[src] = 0;
        int delay = -1;
        int n = 0;
        while(st.size() > 0) {
            auto cur = *st.begin();
            int cur_v = cur.second;
            int cur_wt = cur.first;
            st.erase(st.begin());
            if (vis[cur_v])
                continue;
            vis[cur_v] = 1;
            n++;
            for (auto child: graph[cur_v]) {
                int child_v = child.first;
                int child_w = child.second;
                if (cur_wt + child_w < dist[child_v]) {
                    dist[child_v] = cur_wt + child_w;
                    st.insert({dist[child_v], child_v});
                }
            }
        }
        if (n != N)
            return -1;
        for (int i=1; i<=N; i++) {
            delay = max(delay, dist[i]);
        }
        return delay;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return dijkstra(k, n, times);
    }
};