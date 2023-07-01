#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) return a[1] > b[1];
        else return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> res = {envelopes[0][1]};
        for (int i=1; i<envelopes.size(); i++) {
            if (envelopes[i][1] > res.back()) res.push_back(envelopes[i][1]);
            else res[lower_bound(res.begin(), res.end(), envelopes[i][1]) - res.begin()] = envelopes[i][1];
        }
        return res.size();
    }
};