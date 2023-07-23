#include <bits/stdc++.h> 
using namespace std;

int minimumRemovals(vector<int>& arr, int n, int k)
{
    sort(arr.begin(), arr.end());
    int mn = n-1;
    for (int i=0; i<n; i++) {
        int index = upper_bound(arr.begin(), arr.end(), arr[i]+k)-arr.begin()-1;
        mn = min(mn, n-(index-i+1));
    }
    return mn;
}
