#include <bits/stdc++.h>
using namespace std;
 
int getLongestSubarray(vector<int>& nums, int k){
    map<long long, int> mp;
    int mx=0; 
    long long cur=0;
    for (int i=0; i<nums.size(); i++) {
        cur += nums[i];
        if (cur == k) mx = max(mx, i+1);
        long long rem = cur - k;
        if (mp.find(rem) != mp.end()) {
            mx = max(mx, i-mp[rem]);
        }
        if (mp.find(cur) == mp.end()) mp[cur] = i;
    }
    return mx;
}