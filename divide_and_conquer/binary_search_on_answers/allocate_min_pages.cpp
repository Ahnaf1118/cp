//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int A[], int N, int M, int limit) {
        int pages = 0, cnt = 1;
        for (int i=0; i<N; i++) {
            if (A[i] > limit) return 0;
            if (pages + A[i] > limit) {
                pages = A[i];
                cnt++;
            }
            else {
                pages += A[i];
            }
        }
        return cnt <= M;
    }
    int findPages(int A[], int N, int M) 
    {
        if (M > N) return -1;
        int lo = A[0], hi = accumulate(A, A+N, 0);
        int res = -1;
        while (lo <= hi) {
            int md = (lo+hi) >> 1;
            if (isPossible(A, N, M, md)) {
                res = md;
                hi = md - 1;
            }
            else {
                lo = md + 1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends