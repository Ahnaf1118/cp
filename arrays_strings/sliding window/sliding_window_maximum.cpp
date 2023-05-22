#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> st;
        int n= nums.size();
        int i=0, j=0;
        while(j<n and i<n) {
            st.insert(nums[j]);
            if (st.size() < k) j++;
            else if (st.size()==k) {
                res.push_back(*(--st.end()));
                auto it = st.find(nums[i]);
                if (it != st.end()) st.erase(it);
                i++, j++;
            }
        }
        return res;
    }
};