//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
    int find(int u, vector<int> &par) {
        if (u == par[u]) return u;
        return par[u] = find(par[u], par);
    }
    void merge(int u, int v, vector<int> &par, vector<int> &sz) {
        int pu = find(u, par), pv = find(v, par);
        if (pu == pv) return;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size(); 
        unordered_map<string, int> mp;
        vector<int> par(n+10, 0), sz(n+10, 1);
        for (int i=0; i<n; i++) par[i] = i;
        for (int i=0; i<n; i++) {
            int m = accounts[i].size();
            for (int j=1; j<m; j++) {
                string mail = accounts[i][j];
                if (mp.find(mail) != mp.end()) {
                    merge(i, mp[mail], par, sz);
                }
                else mp[mail] = i;
            }
        }
        vector<string> ans[n+10];
        for (auto acc: mp) {
            ans[find(acc.second, par)].push_back(acc.first);
        }
        vector<vector<string>> res;
        for (int i=0; i<n; i++) {
            if (not ans[i].size()) continue;
            sort(ans[i].begin(), ans[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto a: ans[i]) temp.push_back(a);
            res.push_back(temp);
        }
        return res;
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
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends