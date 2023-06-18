#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i=2; i<=n; i++) {
            int one = stoi(s.substr(i-1, 1));
            if (one >= 1 and one <= 9) dp[i] += dp[i-1];
            int two = stoi(s.substr(i-2, 2));
            if (two >= 10 and two <= 26) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};