//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int minSteps(int m, int n, int d)
	{
	    if (m+n < d) return -1;
	    queue<vector<int>> q;
	    q.push({0, 0});
	    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
	    int steps = 0;
	    while (q.size()) {
	        int sz = q.size();
	        while (sz--) {
	            auto vec = q.front(); q.pop();
	            int x = vec[0], y = vec[1];
	            if (x==d or y==d) return steps;
	            if (x<0 or x>m or y<0 or y>n or dp[x][y]) continue;
	            dp[x][y] = 1;
	            if (not dp[0][y]) q.push({0, y});
	            if (not dp[x][0]) q.push({x, 0});
	            if (not dp[m][y]) q.push({m, y});
	            if (not dp[x][n]) q.push({x, n});
	            int rem_x = m-x, rem_y = n-y;
	            int nx = x + min(rem_x, y), ny = y - min(rem_x, y);
	            if (not dp[nx][ny]) q.push({nx, ny});
	            ny = y + min(rem_y, x), nx = x - min(rem_y, x);
	            if (not dp[nx][ny]) q.push({nx, ny});
	        }
	        steps++;
	    }
	    return -1;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends