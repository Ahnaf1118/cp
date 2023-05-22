#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int mx = -1;
        int n = s.length();
        int i=0, j=0;
        map<char, int> mp;
        while (j<n and i<n) {
            mp[s[j]]++;
            if (mp.size()<k) j++;
            else if (mp.size() == k) {
                mx = max(mx, j-i+1);
                j++;
            }
            else {
                while(mp.size()>k and i<n) {
                    if(mp[s[i]] == 1) mp.erase(s[i]);
                    else mp[s[i]]--;
                    i++;
                }
                if(mp[s[j]] == 1) mp.erase(s[j]);
                else mp[s[j--]]--;
            }
            
        }
        return mx;
    }
};