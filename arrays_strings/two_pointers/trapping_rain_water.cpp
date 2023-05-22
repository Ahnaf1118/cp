#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> L(n, 0), R(n, 0);
        for (int i=1; i<n; i++) L[i] = max(L[i-1], height[i-1]);
        for (int i=n-2; i>=0; i--) R[i] = max(R[i+1], height[i+1]);
        int sum = 0;
        for (int i=0; i<n; i++) sum += max(0, min(L[i], R[i])-height[i]);
        return sum;   
    }
};