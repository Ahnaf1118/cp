//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &arr,int n,int k){
        priority_queue<int, vector<int>> pq;
        vector<int> pre(n, 0);
        pre[0] = arr[0];
        for (int i=1; i<n; i++) pre[i] = arr[i] + pre[i-1];
        pq.push(arr[n-1]);
        for (int i=0; i<n-1; i++) {
            pq.push((i>0)?(pre[i]-pre[i-1]):pre[i]);
            for (int j=i+1; j<n; j++) {
                pq.push(pre[j]-((i>0)?pre[i-1]:0));
            }
        }
        for (int i=0; i<k-1; i++) pq.pop();
        return pq.top();
    }
};

//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends