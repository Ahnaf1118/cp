#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& a, int target) {
    sort(a.begin(), a.end());
    int n = a.size();
    vector<vector<int>> res;
    for (int i=0; i<n-3; i++) {
        if (i>0 and a[i]==a[i-1]) continue;
        for (int j=i+1; j<n-2; j++) {
            if (j!=i+1 and a[j]==a[j-1]) continue;
            int k=j+1, l=n-1;
            while (k < l) {
                int sum = a[i]+a[j]+a[k]+a[l];
                if (sum < target) k++;
                else if (sum > target) l--;
                else {
                    vector<int> temp = {a[i], a[j], a[k], a[l]};
                    res.push_back(temp);
                    k++, l--;
                    while (a[k] == a[k-1]) k++;
                    while (a[l] == a[l+1]) l--;
                }
            }
        }
    } 
    return res;
}