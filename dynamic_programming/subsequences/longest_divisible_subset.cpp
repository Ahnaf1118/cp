#include <bits/stdc++.h> 
using namespace std;

vector<int> divisibleSet(vector<int> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 1), par(n, -1);
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i]%arr[j]==0 or arr[j]%arr[i]==0) {
                if (dp[i]<1+dp[j]) {
                    dp[i] = 1 + dp[j];
                    par[i] = j;
                }
            }
        }
    }
    int mx = *max_element(dp.begin(), dp.end());
    int mx_i = 0;
    for (int i=0; i<n; i++) if (dp[i]==mx) mx_i = i;
    vector<int> res;
    while(mx_i != -1) {
        res.push_back(arr[mx_i]);
        mx_i = par[mx_i];
    }
    return res;
}