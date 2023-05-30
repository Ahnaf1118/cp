#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n==1) return s;
        map<string, bool> mp;
        int mx = 0, mx_i = 0;
        for (int i=0; i<n; i++) {
            int l = i, r = i;
            while(l>=0 and r<n and s[l] == s[r]) {
                if (r-l+1 > mx) mx = r-l+1, mx_i = l;
                l--, r++;
            }
            l = i, r = i+1;
            while(l>=0 and r<n and s[l] == s[r]) {
                if (r-l+1 > mx) mx = r-l+1, mx_i = l;
                l--, r++;
            }
        }
        return s.substr(mx_i, mx);
    }
};