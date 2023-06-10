//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> res, inDegree(V, 0);
	    for (int i=0; i<V; i++) {
	        for (int c: adj[i]) {
	            inDegree[c]++;
	        }
	    }
	    queue<int> q;
	    for (int i=0; i<V; i++) {
	        if (not inDegree[i]) q.push(i);
	    }
	    while(not q.empty()) {
	        int c = q.front(); q.pop();
	        res.push_back(c);
	        for (int ch: adj[c]) {
	            inDegree[ch]--;
	            if (not inDegree[ch]) q.push(ch);
	        }
	    }
	    return res;
	}
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for (int i=0; i<N-1; i++) {
            string s1 = dict[i], s2 = dict[i+1];
            int m = min(s1.size(), s2.size());
            for (int j=0; j<m; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int> res = topoSort(K, adj);
        string s = "";
        for (auto r: res) {
            s += char(r+'a');
        }
        return s;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends