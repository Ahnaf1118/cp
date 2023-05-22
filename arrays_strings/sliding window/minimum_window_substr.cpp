#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s==t) return t;
        map<char, int> smp, tmp;
        for (char c: t) tmp[c]++;
        int n=s.length(), m=tmp.size();
        if (n<m) return "";
        int i=0, j=0; int count=0;
        int x=0, len=n, found=0;
        while(i<n and j<n) {
            smp[s[j]]++;
            if (smp[s[j]] == tmp[s[j]]) count++;
            if (count < m) j++;
            else {
                while(count == m and i<n) {
                    found = true;
                    if (j-i+1 < len) len=j-i+1, x=i;
                    smp[s[i]]--;
                    if (smp[s[i]] < tmp[s[i]]) count--;
                    i++;
                }
                j++;
            }
        } 
        return found?s.substr(x, len):"";
    }
};