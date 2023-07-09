//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kadane(vector<int> &arr) {
        int mx = INT_MIN, cur = 0;
        for (int i=0; i<arr.size(); i++) {
            cur += arr[i];
            mx = max(mx, cur);
            if (cur < 0) cur = 0;
        }
        return mx;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> &M) {
        int mx = INT_MIN;
        for (int i=0; i<C; i++) {
            vector<int> temp(R, 0);
            for (int j=i; j<C; j++) {
                for (int k=0; k<R; k++) {
                    temp[k] += M[k][j];
                }
                mx = max(mx, kadane(temp));
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