#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int lo = 0, hi = n-1;
        while (lo <= hi) {
            int md = (lo+hi)>>1;
            if (matrix[md][0] > target) hi = md - 1;
            else if (matrix[md][m-1] < target) lo = md + 1;
            else {
                auto it = lower_bound(matrix[md].begin(), matrix[md].end(), target);
                if (it == matrix[md].end()) return false;
                if (*it != target) return false;
                if (*it == target) return true;
            }
        }
        return false;
    }
};