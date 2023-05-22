#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, sv(26, 0), pv(26, 0);
        for (auto c: p) pv[c-'a']++;
        int n=s.length(), m=p.length(), i=0, j=0;
        map<vector<int>, bool> mp;
        mp[pv] = true;
        while (j<n) {
            sv[s[j]-'a']++;
            if (j-i+1 < m) j++;
            else {
                if (mp.find(sv) != mp.end()) res.push_back(i);
                sv[s[i]-'a']--;
                i++, j++;
            }
        }
        return res;
    }
};