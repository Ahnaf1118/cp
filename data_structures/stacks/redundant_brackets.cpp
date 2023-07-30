//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        stack<int> stk;
        for (auto c: s) {
            if (c == ')') {
                bool redundant = true;
                while (stk.size() and stk.top() != '(') stk.pop(), redundant = false;
                stk.pop();
                if (redundant) return true;
            }
            else if (c >= 'a' and c <= 'z') continue;
            else stk.push(c);
        }
        return false;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends