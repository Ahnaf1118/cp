#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto &v: cuboids) sort(v.begin(), v.end());
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        vector<int> dp(n, 0);
        for (int i=0; i<n; i++) dp[i] = cuboids[i][2];
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (cuboids[j][1] > cuboids[i][1] or cuboids[j][2] > cuboids[i][2]) continue;
                dp[i] = max(dp[i], cuboids[i][2] + dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};