//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool dfs(int index, int n, int k, vector<int> &subsets, int a[]) {
        if (index == n) return true;
        for (int i=0; i<k; i++) {
            if (subsets[i] - a[index] < 0) continue;
            subsets[i] -= a[index];
            if (dfs(index+1, n, k, subsets, a)) return true;
            subsets[i] += a[index];
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum = accumulate(a, a+n, 0);
        if (sum%k != 0) return false;
        sort(a, a+n, greater<int>());
        vector<int> subsets(k, sum/k);
        return dfs(0, n, k, subsets, a);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends