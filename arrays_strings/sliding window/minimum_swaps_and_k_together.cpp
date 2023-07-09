//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int i=0, j=0, cnt=0, mn=n, cur=0;
        for (int i=0; i<n; i++) cnt += (arr[i]<=k);
        for (int i=0; i<cnt; i++) cur += (arr[i]<=k);
        mn = min(mn, cnt-cur);
        for (int i=cnt; i<n; i++) {
            cur += (arr[i]<=k);
            cur -= (arr[i-cnt]<=k);
            mn = min(mn, cnt-cur);
        }
        return mn;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends