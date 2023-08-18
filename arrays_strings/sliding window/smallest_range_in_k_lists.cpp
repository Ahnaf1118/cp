//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        vector<pair<int, int>> a;
        for (int i=0; i<k; i++) for (int j=0; j<n; j++) a.push_back({arr[i][j], i});
        sort(a.begin(), a.end());
        unordered_map<int, int> mp;
        int i=0, j=0, m=a.size(), x=-1e9, y=1e9;
        while (i<m and j<m) {
            while (mp.size()<k and j<m) {
                auto pr = a[j];
                int num = pr.first, list = pr.second;
                mp[list]++;
                j++;
            }
            while (mp.size()>=k and i<m) {
                if (a[j-1].first-a[i].first < y-x) y=a[j-1].first, x=a[i].first;
                auto pr = a[i];
                int num = pr.first, list = pr.second;
                mp[list]--;
                i++;
                if (mp[list] == 0) mp.erase(list);
            }
        }
        return {x, y};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends