//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        map<int, int> mp;
        for (auto c: s) mp[c-'0']++;
        priority_queue<int, vector<int>> pq;
        for (auto pr: mp) pq.push(pr.second);
        while (k) {
            int cur = pq.top(); pq.pop();
            pq.push(cur-1);
            k--;
        }
        int res = 0;
        while (not pq.empty()) {
            res += pq.top()*pq.top();
            pq.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends