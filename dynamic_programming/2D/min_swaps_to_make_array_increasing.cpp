#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int index, int swapped, int n, vector<int> &a, vector<int> &b, vector<vector<int>> &dp) {
        if (index >= n) return 0;
        if (dp[index][swapped] != -1) return dp[index][swapped];
        int mn=1e9, x=a[index-1], y=b[index-1];
        if (swapped) swap(x, y);
        if (a[index] > x and b[index] > y) mn = min(mn, dfs(index+1, 0, n, a, b, dp));
        if (a[index] > y and b[index] > x) mn = min(mn, 1 + dfs(index+1, 1, n, a, b, dp));
        return dp[index][swapped] = mn;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return dfs(1, 0, n+1, nums1, nums2, dp);
    }
};