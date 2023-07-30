#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        for (auto c: s) mp[c]++;
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        for (auto pr: mp) pq.push({pr.second, pr.first});
        string res;
        auto pr = pq.top(); pq.pop();
        res.push_back(pr.second);
        if (pr.first > 1) pq.push({pr.first-1, pr.second});
        pair<int, char> temp;
        while (pq.size()) {
            auto pr = pq.top(); pq.pop();
            if (pr.second == res.back()) {
                if (pq.empty()) return "";
                temp = pr;
                pr = pq.top(); pq.pop();
                res.push_back(pr.second);
                pq.push(temp);
                if (pr.first > 1) pq.push({pr.first - 1, pr.second});
            }
            else {
                res.push_back(pr.second);
                if (pr.first > 1) pq.push({pr.first - 1, pr.second});
            }
        }
        return res;
    }
};