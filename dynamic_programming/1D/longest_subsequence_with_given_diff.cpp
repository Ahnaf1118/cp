#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        unordered_map<int, int> mp;
        mp[arr[0]] = 1;
        vector<int> dp(n, 1);
        for (int i=1; i<n; i++) {
            if (mp.find(arr[i]-diff) != mp.end()) dp[i] = max(dp[i], 1 + mp[arr[i]-diff]);
            mp[arr[i]] = dp[i];
        }
        return *max_element(dp.begin(), dp.end());
    }
};