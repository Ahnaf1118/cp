#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count_invalid(string s) {
        stack<char> stk;
        for (auto c: s) {
            if (c != '(' and c != ')') continue;
            if (c == ')' and not stk.empty() and stk.top() == '(') stk.pop();
            else stk.push(c);
        }
        return stk.size();
    }
    void dfs(int rem, string s, vector<string> &combinations, unordered_map<string, int> &mp) {
        if (mp.find(s) != mp.end()) return;
        mp[s]++;
        if (rem < 0) return;
        if (not rem and not count_invalid(s)) combinations.push_back(s);
        for (int i=0; i<s.size(); i++) dfs(rem-1, s.substr(0, i)+s.substr(i+1), combinations, mp);
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_map<string, int> mp;
        vector<string> combinations;
        dfs(count_invalid(s), s, combinations, mp);
        return combinations;
    }
};