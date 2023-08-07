//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kadane(vector<int> &arr) {
        int mx = *max_element(arr.begin(), arr.end()), cur = 0;
        for (int i=0; i<(int)arr.size(); i++) {
            cur += arr[i];
            mx = max(mx, cur);
            if (cur < 0) cur = 0;
        }
        return mx;
    }
    int maximumSumRectangle(int r, int c, vector<vector<int>> mat) {
        int mx = -1e9;
        for (int i=0; i<c; i++) {
            vector<int> arr(r, 0);
            for (int j=i; j<c; j++) {
                for (int k=0; k<r; k++) {
                    arr[k] += mat[k][j];
                }
                mx = max(mx, kadane(arr));
            }
        }
        return mx;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends