#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_possible(int n, int days, int limit, vector<int> & weights) {
        if (days > n) return 0;
        int cur = 0, cnt = 1;
        for (int i=0; i<n; i++) {
            cur += weights[i];
            if (weights[i] > limit) return 0;
            if (cur > limit) {
                cur = weights[i], cnt++;
            }
        }
        return (cnt <= days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo = weights[0], hi = accumulate(weights.begin(), weights.end(), 0);
        int res = -1;
        while(lo <= hi) {
            int md = (lo+hi)>>1;
            if (is_possible(n, days, md, weights)) {
                res = md;
                hi = md - 1;
            }
            else {
                lo = md + 1;
            }
        }
        return res;
    }
};