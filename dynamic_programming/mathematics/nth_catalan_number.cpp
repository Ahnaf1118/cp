//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        vector<int> dp(2*n+10, 0);
        dp[0] = dp[1] = 1;
        for (int i=2; i<=2*n+1; i++) dp[i] = i*dp[i-1];
        return dp[2*n]/(dp[n+1]*dp[n]);
    }
};

//{ Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends