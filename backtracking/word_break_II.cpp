//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> helper(string s, unordered_set<string> &st) {
        vector<string> res;
        for (int i=0; i<s.size(); i++) {
            string word = s.substr(0, i+1);
            if (not st.count(word)) continue;
            if (word == s) res.push_back(word);
            else {
                vector<string> sub_res = helper(s.substr(i+1), st);
                for (auto phrase: sub_res) res.push_back(word + ' ' + phrase);
            }
        }
        return res;
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        unordered_set<string> st(dict.begin(), dict.end());
        return helper(s, st);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends