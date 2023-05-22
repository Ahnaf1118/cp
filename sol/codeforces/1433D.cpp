#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool bfs(vector<ll> &vertices, vector<pair<ll, ll>> &edges) {
    vector<bool> vis(vertices.size(), false);
    deque<pair<ll, ll>> q;
    q.push_back({0, vertices[0]});
    vis[0] = true;
    while(!q.empty()) {
        pair<ll, ll> cur = q.front();
        q.pop_front();
        ll cur_index = cur.first;
        ll cur_power = cur.second;
        for (int i=0; i<vertices.size(); i++) {
            if (vis[i] || vertices[i] == cur_power || i == cur_index)
                continue;
            vis[i] = true;
            q.push_back({i, vertices[i]});
            edges.push_back({cur_index+1, i+1});
        }
    }
    if (edges.size())
        return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int s = 5e3 + 10;
        vector<ll> vertices;
        for (int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            vertices.push_back(temp);
        }
        // sort(vertices.begin(), vertices.end());
        vector<pair<ll, ll>> edges;
        bool res = bfs(vertices, edges);
        if (res) {
            cout << "YES\n";
            for (auto edge: edges) {
                cout << edge.first << ' ' << edge.second << endl;
            }
        }
        else
            cout << "NO\n";        
    }
}