#include <bits/stdc++.h>
using namespace std;

int dfs(int index, int n, vector<int> &days, vector<int> &cost, vector<int> &dp) {
    if (index >= n) return 0;
    if (dp[index] != -1) return dp[index];
    int it1 = distance(days.begin(), lower_bound(days.begin(), days.end(), days[index]+1));
    int it2 = distance(days.begin(), lower_bound(days.begin(), days.end(), days[index]+7));
    int it3 = distance(days.begin(), lower_bound(days.begin(), days.end(), days[index]+30));
    int op1 = cost[0] + dfs(it1, n, days, cost, dp);
    int op2 = cost[1] + dfs(it2, n, days, cost, dp);
    int op3 = cost[2] + dfs(it3, n, days, cost, dp);
    return dp[index] = min({op1, op2, op3});
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1, -1);
    return dfs(0, n, days, cost, dp);
}