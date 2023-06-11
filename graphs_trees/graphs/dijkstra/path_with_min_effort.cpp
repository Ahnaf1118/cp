//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool in_range(int x, int y, int n, int m) {
        if (x<0 or x>=n) return 0;
        if (y<0 or y>=m) return 0;
        return 1;
    }
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        pq.push({0, {0, 0}});
        int xp[] = {0, 0, -1, 1}, yp[] = {-1, 1, 0, 0};
        while(not pq.empty()) {
            auto pr = pq.top();
            int dis = pr.first, x = pr.second.first, y = pr.second.second;
            pq.pop();
            for (int i=0; i<4; i++) {
                int ch_x = x + xp[i], ch_y = y + yp[i];
                if (not in_range(ch_x, ch_y, n, m)) continue;
                int temp = max(abs(heights[ch_x][ch_y] - heights[x][y]), dis);
                if (temp < dist[ch_x][ch_y]) {
                    dist[ch_x][ch_y] = temp;
                    pq.push({dist[ch_x][ch_y], {ch_x, ch_y}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends