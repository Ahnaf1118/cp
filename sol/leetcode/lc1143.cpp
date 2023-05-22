#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1005][1005];
    int lcs(int i, int j, string &s1, string &s2) {
        if (i<0 or j<0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mx = lcs(i-1, j-1, s1, s2) + (s1[i]==s2[j]);
        mx = max(mx, lcs(i-1, j, s1, s2));
        mx = max(mx, lcs(i, j-1, s1, s2));
        return dp[i][j] = mx;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        int l1 = text1.length()-1;
        int l2 = text2.length()-1;
        return lcs(l1, l2, text1, text2);
    }
};
