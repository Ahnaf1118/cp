#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> larr(n, 0), rarr(n, 0);
        int lmn = prices[0], rmx = prices[n-1];
        for (int i=1; i<n; i++) {
            larr[i] = max(larr[i-1], prices[i]-lmn);
            lmn = min(lmn, prices[i]);
        }
        for (int i=n-2; i>=0; i--) {
            rarr[i] = max(rarr[i+1], rmx-prices[i]);
            rmx = max(rmx, prices[i]);
        }
        vector<int> res(n, 0);
        for (int i=0; i<n; i++) res[i] = larr[i] + rarr[i];
        return *max_element(res.begin(), res.end());
    }
};