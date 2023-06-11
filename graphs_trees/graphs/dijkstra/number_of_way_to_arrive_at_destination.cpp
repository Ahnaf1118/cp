//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> graph[n];
        for (auto road: roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        vector<int> dist(n, 2e9), ways(n, 0);
        dist[0] = 0, ways[0] = 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while(not pq.empty()) {
            auto pr = pq.top(); pq.pop();
            int vertex = pr.second, dis = pr.first;
            for (auto child_pr: graph[vertex]) {
                int child = child_pr.first, child_dis = child_pr.second;
                int temp = dis + child_dis;
                if (temp < dist[child]) {
                    dist[child] = temp;
                    ways[child] = ways[vertex];
                    pq.push({dist[child], child});
                }
                else if (temp == dist[child]) {
                    ways[child] = (ways[child] + ways[vertex])%(int)(1e9+7);
                }
            }
        }
        return ways[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends