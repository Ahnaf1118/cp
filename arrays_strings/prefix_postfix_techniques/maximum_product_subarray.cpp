//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    long long mx = -2e9;
	    long long pre = 1, suff = 1;
	    for (int i=0; i<n; i++) {
	        if (pre == 0) pre = 1;
	        if (suff == 0) suff = 1;
	        pre *= 1ll*arr[i];
	        suff *= 1ll*arr[n-i-1];
	        mx = max({mx, pre, suff});
	    }
	    return mx;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends