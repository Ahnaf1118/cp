#include <bits/stdc++.h>
using namespace std;
// doesnt work for negative numbersl
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0, sum=0, cnt=0;
        while(j<n and i<n) {
            sum += nums[j];
            if (sum<k) j++;
            else if(sum==k) cnt++, j++;
            else {
                while(sum>k) sum -= nums[i], i++;
                sum -= nums[j];
            }
        }
        return cnt;
    }
};