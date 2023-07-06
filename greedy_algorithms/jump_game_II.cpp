#include <bits/stdc++.h>
using namespace std;

class Solution {
public:   
    int jump(vector<int>& nums) {
        int left = 0, right = 0, steps = 0;
        while (right < nums.size()-1) {
            int mx = 0;
            for (int i=left; i<=right; i++) mx = max(mx, i+nums[i]);
            left = right + 1;
            if (mx <= right) return -1;
            right = mx;
            steps++;
        }
        return steps;
    }
};