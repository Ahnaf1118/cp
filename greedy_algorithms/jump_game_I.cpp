#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(); int cur = 0;
        for (int i=0; i<n; i++) {
            cur--;
            cur = max(nums[i], cur);
            if (not cur and i!=n-1) return false;
        }
        return true;
    }
};