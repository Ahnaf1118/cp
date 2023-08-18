//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    long long cur = 0, res = -1e17;
    vector<long long> mx(n, 0ll);
    for (int i=0; i<n; i++) {
        cur += a[i];
        if (cur < 0) cur = 0;
        mx[i] = cur;
    }
    cur = 0;
    for (int i=0; i<k; i++) {
        cur += a[i];
    }
    res = max(res, cur);
    for (int i=k; i<n; i++) {
        cur -= a[i-k];
        cur += a[i];
        res = max(res, cur + mx[i-k]);
    }
    return res;
}