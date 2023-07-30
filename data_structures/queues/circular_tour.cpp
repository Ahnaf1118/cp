//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       vector<int> a(n, 0);
       for (int i=0; i<n; i++) a[i] = p[i].petrol - p[i].distance;
       vector<int> pre(n, 0);
       pre[0] = a[0];
       for (int i=1; i<n; i++) pre[i] = pre[i-1] + a[i];
       if (pre[n-1] < 0) return -1;
       int start = 0, feul = 0;
       for (int i=0; i<n; i++) {
           feul += a[i];
           if (feul < 0) start = i+1, feul = 0;
       }
       if (start!=n and feul >= (start>0?pre[start-1]:0)) return start;
       else return -1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends