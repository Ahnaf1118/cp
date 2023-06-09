//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int v, vector<int> &vis, vector<int> adj[]) {
        bool res = true;
        for (int c: adj[v]) {
            if (vis[c] == vis[v]) return false;
            if (vis[c] != -1) continue;
            vis[c] = vis[v]^1;
            res &= dfs(c, vis, adj);
        }
        return res;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> vis(V+10, -1);
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i] == -1)
	        {
	            vis[i] = 0;
	            if (not dfs(i, vis, adj)) return false;
	        }
	    }
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends