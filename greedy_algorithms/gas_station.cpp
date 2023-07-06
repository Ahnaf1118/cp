#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;
        int index = 0, cur = 0;
        for (int i=0; i<gas.size(); i++) {
            cur += gas[i]-cost[i];
            if (cur < 0) cur = 0, index = i + 1;
        }
        return index;
    }
};