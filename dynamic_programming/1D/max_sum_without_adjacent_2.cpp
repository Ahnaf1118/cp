//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int findMaxSum(vector<int>& a){
    int n = a.size();
    vector<int> dp(n, 0);
    dp[0] = a[0];
    dp[1] = a[0] + a[1];
    dp[2] = max({a[0]+a[1], a[1]+a[2], a[0]+a[2]});
    for (int i=3; i<n; i++) {
        dp[i] = max({dp[i-1], dp[i-2]+a[i], dp[i-3]+a[i-1]+a[i]});
    } 
    return dp[n-1];
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends