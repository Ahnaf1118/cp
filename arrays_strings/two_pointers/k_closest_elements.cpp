#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if (it != arr.begin()) it--;
        int index = distance(arr.begin(), it);
        int l=index, r=index+1;
        while(k--) {
            if (l<0) {
                res.push_back(arr[r]), r++;
                continue;
            }
            if (r>=arr.size()) {
                res.push_back(arr[l]), l--;
                continue;
            }
            if (abs(arr[l]-x)<=abs(arr[r]-x)) res.push_back(arr[l]), l--;
            else res.push_back(arr[r]), r++;
        }
        sort(res.begin(), res.end());
        return res;
    }
};