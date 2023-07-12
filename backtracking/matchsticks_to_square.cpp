#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ms = {0, 0, 0, 0};
    bool dfs(int index, int n, int side, vector<int> &a) {
        if (index == n) return true;
        for (int i=0; i<4; i++) {
            if (ms[i]+a[index] > side) continue;
            ms[i] += a[index];
            if (dfs(index+1, n, side, a)) return true;
            ms[i] -= a[index];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int side = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (side % 4) return false;
        side /= 4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return dfs(0, n, side, matchsticks);
    }
};