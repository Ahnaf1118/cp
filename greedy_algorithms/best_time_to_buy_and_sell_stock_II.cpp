#include <bits/stdc++.h>
using namespace std;

//greedy
long getMaximumProfit(long *values, int n)
{
    vector<long> slopes(n, 0);
    for (int i=1; i<n; i++) slopes[i] = values[i]-values[i-1];
    long profit = 0;
    for (auto slope: slopes) profit += max(0l, slope);
    return profit;
}