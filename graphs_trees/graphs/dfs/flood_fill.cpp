//leetcode 733
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i, int j, int ic, int fc, vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();
        if (i<0 || j<0 || i>=n || j>=m) return;
        if (image[i][j] != ic) return;
        image[i][j] = fc;
        dfs(i-1, j, ic, fc, image);
        dfs(i+1, j, ic, fc, image);
        dfs(i, j-1, ic, fc, image);
        dfs(i, j+1, ic, fc, image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ic = image[sr][sc];
        if (ic != color)
            dfs(sr, sc, ic, color, image);
        return image;
    }
};