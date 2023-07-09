#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int index, int end, int n, vector<vector<int>> &jobs, vector<int> &dp) {
        if (index >= n) return 0;
        if (jobs[index][0] < end) return dfs(index+1, end, n, jobs, dp);
        if (dp[index] != -1) return dp[index];
        return dp[index] = max(dfs(index+1, end, n, jobs, dp), jobs[index][2]+dfs(index+1, jobs[index][1], n, jobs, dp));
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs(n, vector<int>(3, 0));
        for (int i=0; i<n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n, -1);
        return dfs(0, 0, n, jobs, dp);
    }
};