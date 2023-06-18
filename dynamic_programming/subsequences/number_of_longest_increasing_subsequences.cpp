#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[j] >= nums[i]) continue;
                int temp = dp[j] + 1;
                if (temp > dp[i]) dp[i] = temp, cnt[i] = cnt[j];
                else if (temp == dp[i]) cnt[i] += cnt[j];
            }
        }
        int mx = *max_element(dp.begin(), dp.end());
        int ways = 0;
        for (int i=0; i<n; i++) {
            if (mx != dp[i]) continue;
            ways += cnt[i];
        }
        return ways;
    }
};