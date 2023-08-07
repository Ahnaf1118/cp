//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int bits(int n) {
        int k = 0;
        while (n) k++, n>>=1;
        return k;
    }
    int dfs(int n, unordered_map<int, int> mp) {
        if (n <= 0) return n;
        if (mp.find(n) != mp.end()) return mp[n];
        int b = bits(n)-1;
        return mp[n] = b*(1<<(b-1)) + n-(1<<b)+1 + dfs(n-(1<<b), mp);
    }
    int countSetBits(int n)
    {
        unordered_map<int, int> mp;
        return dfs(n, mp);
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends