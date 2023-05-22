#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26, 0);
        for (auto c: s1) v1[c-'a']++;
        map<vector<int>, bool> mp;
        mp[v1] = true;
        vector<int> v2(26, 0);
        int n=s2.length(), m=s1.length(), i=0, j=0;
        while(j<n) {
            v2[s2[j]-'a']++;
            if (j-i+1 < m) j++;
            else {
                if (mp.find(v2) != mp.end()) return true;
                v2[s2[i]-'a']--;
                i++, j++;
            }
        }
        return false;
    }
};