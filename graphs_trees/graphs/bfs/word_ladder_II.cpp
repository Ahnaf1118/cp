//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<vector<string>> res;
        vector<string> used = {beginWord};
        int level = 0, shortest = 2e9;
        while (not q.empty()) {
            vector<string> cur = q.front(); q.pop();
            if (cur.size() > level) {
                level++;
                for (auto it: used) st.erase(it);
                used.clear();
            }
            if (cur.back() == endWord) {
                if (cur.size() > shortest) break;
                shortest = cur.size();
                res.push_back(cur);
            }
            string word = cur.back();
            for (int i=0; i<word.size(); i++) {
                string temp = word;
                for (int c='a'; c<='z'; c++) {
                    temp[i] = c;
                    if (st.count(temp)) {
                        used.push_back(temp);
                        vector<string> vec = cur;
                        vec.push_back(temp);
                        q.push(vec);
                    }
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends