//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int> dist(1e5, 1e9);
        queue<pair<int, int>> q;
        q.push({start, 0});
        dist[start] = 0;
        while(not q.empty()) {
            auto top = q.front(); q.pop();
            int val = top.first, steps = top.second;
            if (val == end) return steps;
            for (auto ar: arr) {
                int ch_val = (val * ar)%(int)1e5;
                if (steps + 1 < dist[ch_val]) {
                    dist[ch_val] = steps + 1;
                    q.push({ch_val, dist[ch_val]});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends