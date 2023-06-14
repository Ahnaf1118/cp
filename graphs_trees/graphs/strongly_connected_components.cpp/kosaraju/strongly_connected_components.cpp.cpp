//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int v, vector<int> &vis, vector<vector<int>>& adj, stack<int> &stk) {
	    vis[v] = 1;
	    for (auto c: adj[v]) {
	        if (vis[c]) continue;
	        dfs(c, vis, adj, stk);
	    }
	    stk.push(v);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V, 0);
        stack<int> stk;
        for (int i=0; i<V; i++) {
            if (vis[i]) continue;
            dfs(i, vis, adj, stk);
        }
        vector<vector<int>> adj_t(V, vector<int>());
        for (int i=0; i<V; i++) {
            vis[i] = 0;
            for (auto c: adj[i]) {
                adj_t[c].push_back(i);
            }
        }
        stack<int> stk_2;
        int scc = 0;
        while(not stk.empty()) {
            int v = stk.top(); stk.pop();
            if (vis[v]) continue;
            dfs(v, vis, adj_t, stk_2);
            scc++;
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends