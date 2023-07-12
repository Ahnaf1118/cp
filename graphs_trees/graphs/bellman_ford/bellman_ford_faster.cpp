//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void bellman_ford(int n, vector<vector<int>> &edges, vector<int> &dist) {
        dist[edges[0][0]] = 0;
        for (int i=0; i<n; i++) {
            for (auto edge: edges) {
                int u = edge[0], v = edge[1], wt = edge[2];
                if (dist[u] ==  1e9) continue;
                dist[v] = min(dist[v], dist[u] + wt);
                dist[v] = max(dist[v], (int)-1e9);
            }
        }
    }
    void bellman_ford_neg(int n, vector<vector<int>> &edges, vector<int> &dist) {
        for (int i=0; i<n; i++) {
            for (auto edge: edges) {
                int u = edge[0], v = edge[1], wt = edge[2];
                if (dist[u] ==  1e9) continue;
                dist[v] = max(dist[v], (int)-1e9);
                if (dist[u] + wt < dist[v]) dist[v] = -1e9; 
            }
        }
    }
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    if (not edges.size()) return false;
	    vector<int> dist(n, 1e9);
	    bellman_ford(n-1, edges, dist);
	    bellman_ford_neg(1, edges, dist);
	    for (auto d: dist) if (d == -1e9) return true;
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends