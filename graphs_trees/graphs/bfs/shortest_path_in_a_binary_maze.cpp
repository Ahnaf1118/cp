//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool in_range(int x, int y, int n, int m, vector<vector<int>> &depth, vector<vector<int>> &grid) {
        if (x<0 or x>=n) return 0;
        if (y<0 or y>=m) return 0;
        if (depth[x][y] != 1e9) return 0;
        if (not grid[x][y]) return 0;
        return 1;
    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> depth(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q;
        depth[source.first][source.second] = 0;
        q.push({source});
        int x_ch[4] = {0, 0, -1, 1};
        int y_ch[4] = {-1, 1, 0, 0};
        while(not q.empty()) {
            int x = q.front().first, y = q.front().second; q.pop();
            for (int i=0; i<4; i++) {
                int ch_x = x + x_ch[i], ch_y = y + y_ch[i];
                if (not in_range(ch_x, ch_y, n, m, depth, grid)) continue;
                depth[ch_x][ch_y] = depth[x][y] + 1;
                q.push({ch_x, ch_y});
            }
        }
        return depth[destination.first][destination.second]==1e9?-1:depth[destination.first][destination.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends