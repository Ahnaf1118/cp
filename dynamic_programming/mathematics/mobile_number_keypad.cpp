//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long getCount(int n)
	{
	    vector<long long> res(10, 1);
	    for (int j=2; j<=n; j++) {
	        vector<long long> temp(10, 0);
	        temp[0] = res[0]+res[8];
	        temp[1] = res[1]+res[4]+res[2];
	        temp[2] = res[1]+res[2]+res[3]+res[5];
	        temp[3] = res[2]+res[3]+res[6];
	        temp[4] = res[1]+res[4]+res[5]+res[7];
	        temp[5] = res[2]+res[4]+res[5]+res[6]+res[8];
	        temp[6] = res[3]+res[5]+res[6]+res[9];
	        temp[7] = res[4]+res[7]+res[8];
	        temp[8] = res[0]+res[5]+res[7]+res[8]+res[9];
	        temp[9] = res[6]+res[8]+res[9];
	        res = temp;
		}
		return accumulate(res.begin(), res.end(), 0ll);
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends