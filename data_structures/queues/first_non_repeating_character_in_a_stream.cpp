//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		    map<char, int> mp;
		    queue<char> q;
		    string res;
		    for (auto c: a) {
		        mp[c]++;
		        if (mp[c] == 1) {
		            q.push(c);
		            res.push_back(q.front());
		        }
		        else {
		            while (q.size() and mp[q.front()]>1) q.pop();
		            if (q.size()) res.push_back(q.front());
		            else res.push_back('#');
		        }
		    }
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends