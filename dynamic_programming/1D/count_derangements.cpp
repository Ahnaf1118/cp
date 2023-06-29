#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
long long int countDerangements(int n) {
    vector<long long> dp(n+1, 0);
    dp[1] = 0, dp[2] = 1;
    for (long long i=3; i<=n; i++) dp[i] = (((i-1)%M)*((dp[i-1]+dp[i-2])%M))%M;
    return dp[n];
}