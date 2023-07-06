#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<pair<int, int>> next(n, {0, 0}), pre(n, {0, 0});
        stack<pair<int, int>> stk; stk.push({-1, -1});
        for (int i=0; i<n; i++) {
            while (stk.top().first >= heights[i]) stk.pop();
            pre[i] = stk.top();
            stk.push({heights[i], i});
        }
        while (not stk.empty()) stk.pop();
        stk.push({-1, -1});
        for (int i=n-1; i>=0; i--) {
            while (stk.top().first >= heights[i]) stk.pop();
            next[i] = stk.top();
            stk.push({heights[i], i});
        }
        int mx = 0;
        for (int i=0; i<n; i++) {
            int left = pre[i].second;
            int right = next[i].second;
            if (left == -1) left = 0;
            else left++;
            if (right == -1) right = n-1;
            else right--;
            int width = right-left+1;
            mx = max(mx, heights[i]*width);
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int mx = 0;
        vector<int> row(matrix[0].size(), 0);
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                if (matrix[i][j]-'0') row[j]++;
                else row[j] = 0;
            }
            for (int j=0; j<matrix[0].size(); j++) {
                cout << row[j] << ' ';
            }
            cout << endl;
            mx = max(mx, largestRectangleArea(row));
        }
        return mx;
    }
};