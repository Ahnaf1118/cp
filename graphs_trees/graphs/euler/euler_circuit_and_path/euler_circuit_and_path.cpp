//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int v, vector<int> &vis, vector<int> adj[]) {
        vis[v] = 1;
        for (int c: adj[v]) {
            if (vis[c]) continue;
            dfs(c, vis, adj);
        }
    }
	int isEularCircuit(int V, vector<int>adj[]){
	    vector<int> vis(V, 0);
	    vector<int> degree(V, 0);
	    bool dfsed = false;
	    for (int i=0; i<V; i++) {
	        degree[i] = adj[i].size();
	        if (not degree[i]) continue;
	        if (vis[i]) continue;
	        if (not dfsed) dfs(i, vis, adj), dfsed = true;
	        else if (degree[i]) return 0;
	    }
	    int cnt = 0;
	    for (int i=0; i<V; i++) cnt += (degree[i]&1);
	    if (cnt == 0) return 2;
	    else if (cnt == 2) return 1;
	    else return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEularCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends