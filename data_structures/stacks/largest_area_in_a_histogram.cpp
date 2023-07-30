//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<pair<long long, int>> stk;
        stk.push({-1, -1});
        vector<int> pre(n, 0), post(n, 0);
        for (int i=0; i<n; i++) {
            while (stk.top().first != -1 and stk.top().first >= arr[i]) stk.pop();
            pre[i] = stk.top().second;
            stk.push({arr[i], i});
        }
        while (stk.size()) stk.pop();
        stk.push({-1, -1});
        for (int i=n-1; i>=0; i--) {
            while (stk.top().first != -1 and stk.top().first >= arr[i]) stk.pop();
            post[i] = stk.top().second;
            stk.push({arr[i], i});
        }
        long long mx = 0ll;
        for (int i=0; i<n; i++) {
            int left = pre[i]+1;
            int right = post[i]==-1?n-1:post[i]-1;
            mx = max(mx, arr[i]*1ll*(right-left+1));
        }
        return mx;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends