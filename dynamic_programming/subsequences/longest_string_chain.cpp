#include <bits/stdc++.h>
using namespace std;

bool comp(string &a, string &b) {
    return a.size() < b.size();
}
bool compare(string &a, string &b) {
    if (a.size() != b.size()+1) return false;
    int i=0, j=0;
    while(i<a.size()) {
        if (a[i] == b[j]) i++, j++;
        else i++;
    }
    return i==a.size() and j==b.size();
} 
int longestStrChain(vector<string> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), comp);
    vector<int> dp(n, 1);
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (compare(arr[i], arr[j])) dp[i] = max(dp[i], 1 + dp[j]);
        }
    }
    int mx = *max_element(dp.begin(), dp.end());
    return mx;
}