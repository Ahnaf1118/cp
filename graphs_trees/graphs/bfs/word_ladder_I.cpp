//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string start, string target, vector<string>& wordList) {
        int n = start.size();
        set<string> st;
        for (auto word: wordList) st.insert(word);
        queue<pair<string, int>> q;
        q.push({start, 1});
        while (not q.empty()) {
            auto pr = q.front(); q.pop();
            string cur = pr.first;
            int level = pr.second;
            if (cur == target) return level;
            for (int i=0; i<n; i++) {
                string temp = cur;
                for (int c='a'; c<='z'; c++) {
                    if (c == temp[i]) continue;
                    temp[i] = c;
                    if (st.count(temp)) {
                        q.push({temp, level+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends