#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int half_sum = 0;
    int dp[205][20005];
    bool dfs(int index, vector<int>&nums, int cur_sum) {
        if (index < 0)
            return false;
        if (cur_sum == half_sum) {
            return true;
        }
        if (dp[index][cur_sum] != -1)
            return dp[index][cur_sum];
        bool res = false;
        res |= dfs(index - 1, nums, cur_sum);
        res |= dfs(index - 1, nums, cur_sum + nums[index]);
        return dp[index][cur_sum] = res;
    }
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum = 0;
        for (auto num: nums)
            sum += num;
        if (sum & 1)
            return false;
        sum /= 2;
        half_sum = sum;
        return dfs(nums.size()-1, nums, 0);
    }
    bool canPartition2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (auto num: nums)
            sum += num;
        if (sum & 1)
            return false;
        sum /= 2;
        bitset<100000> b;
        b[0] = 1;
        for (auto num: nums)
            b |= (b << num);
        return b[sum];
    }
};