#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        if (n==2) return max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], dp[0]);
        for (int i=2; i<n; i++) dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        vector<int> v1(nums.size()-1, 0), v2(nums.size()-1, 0);
        copy(nums.begin()+1, nums.end(), v1.begin());
        copy(nums.begin(), nums.end()-1, v2.begin());
        return max(solve(v2), solve(v1));
    }
};