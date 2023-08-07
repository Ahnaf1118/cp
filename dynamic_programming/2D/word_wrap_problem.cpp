//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[505][2005];
    int dfs(int index, int rem, int k, int n, vector<int> &nums) {
        if (index == n) return 0;
        if (dp[index][rem] != -1) return dp[index][rem];
        int mn = 2e9;
        if (nums[index] > rem) mn = min(mn, (rem+1)*(rem+1) + dfs(index+1, k-nums[index]-1, k, n, nums));
        else mn = min((rem+1)*(rem+1) + dfs(index+1, k-nums[index]-1, k, n, nums), dfs(index+1, rem-nums[index]-1, k, n, nums));
        return dp[index][rem] = mn;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return dfs(0, k, k, n, nums);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends