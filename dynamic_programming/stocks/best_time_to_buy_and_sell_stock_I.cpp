#include <bits/stdc++.h> 
using namespace std;

int maximumProfit(vector<int> &prices){
    int mx=0, cur=0;
    vector<int> slopes = prices;
    slopes[0] = 0;
    for (int i=1; i<prices.size(); i++) slopes[i] -= prices[i-1];
    for (int i=0; i<slopes.size(); i++) {
        cur += slopes[i];
        mx = max(mx, cur);
        if (cur < 0) cur = 0;
    }
    return mx;
}