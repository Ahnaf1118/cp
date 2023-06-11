//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<int> dist(n, 1e9); dist[src] = 0;
        // priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>> > pq;
        // cant use greedy since stops are also a determining factor
        queue<pair<int, pair<int, int>>> pq;
        vector<pair<int, int>> graph[n];
        for (auto flight: flights) {
            int u = flight[0], v = flight[1], cost = flight[2];
            graph[u].push_back({v, cost});
        }
        pq.push({dist[src], {src, 0}});
        while(not pq.empty()) {
            auto triplet = pq.front();
            int dis = triplet.first, vertex = triplet.second.first, steps = triplet.second.second;
            pq.pop();
            for (auto ch_pr: graph[vertex]) {
                int ch_vertex = ch_pr.first, ch_cost = ch_pr.second;
                int temp = dis + ch_cost;
                if (temp < dist[ch_vertex] and steps+1 <= K+1) {
                    dist[ch_vertex] = temp;
                    pq.push({dist[ch_vertex], {ch_vertex, steps+1}});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends