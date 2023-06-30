#include <bits/stdc++.h>
using namespace std;

bool wildcardMatching(string pattern, string text)
{
   int n = text.size(), m = pattern.size();
   vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));
   dp[0][0] = 1;
   for (int i=1; i<=m; i++) {
      if (pattern[i-1] != '*') break;
      dp[0][i] = 1;
   }
   for (int i=1; i<=n; i++) {
      for (int j=1; j<=m; j++) {
         if (text[i-1] == pattern[j-1]) dp[i][j] = dp[i-1][j-1];
         else if (pattern[j-1] == '?') dp[i][j] = dp[i-1][j-1];
         else if (pattern[j-1] == '*') dp[i][j] = dp[i-1][j] or dp[i][j-1];
         else dp[i][j] = 0;
      }
   }
   return dp[n][m];
}
