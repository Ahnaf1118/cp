//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        bool check(int n, int zeros) {
            int cnt = 0, prod = 5;
            while (prod <= n) {
                cnt += n/prod;
                prod *= 5;
            }
            return cnt >= zeros;
        }
        int findNum(int n)
        {
            if (n == 0) return 1; 
            if (n == 1) return 5;
            int lo=0, hi=5*n;
            while (lo < hi) {
                int md = (lo + hi) >> 1;
                if (check(md, n)) hi = md;
                else lo = md + 1;
            }
            return lo;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends