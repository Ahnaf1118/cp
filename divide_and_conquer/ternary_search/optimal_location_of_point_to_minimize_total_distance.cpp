//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    double dist(double x1, double y1, double x2, double y2) {
        return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    }
    double total_dist(double x, double a, double b, double c, vector<pair<int, int>> &p) {
        double total = 0.0;
        double y = -1*(a*x + c)/b;
        for (auto pr: p) {
            total += dist(x, y, pr.first, pr.second);
        }
        return total;
    }
    double findOptimumCost(tuple<int,int,int>l, vector<pair<int,int>>p, int n){
	    double a = get<0>(l);
	    double b = get<1>(l);
	    double c = get<2>(l);
	    double lo = -1e6, hi = 1e6;
	    double res = 0;
	    while (abs(hi-lo) > 1e-8) {
	        double md1 = lo + (hi-lo)/3, md2 = hi - (hi-lo)/3;
	        double dist1 = total_dist(md1, a, b, c, p);
	        double dist2 = total_dist(md2, a, b, c, p);
	        res = total_dist((md1+md2)/2, a, b, c, p);
	        if (dist1 < dist2) hi = md2;
	        else if (dist1 > dist2) lo = md1;
	        else lo = md1, hi = md2;
	    }
	    return res;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    tuple<int,int,int>line;
	    int a, b, c;
	    cin >> a >> b >> c;
	    line = make_tuple(a, b, c);
	    int n;
	    cin >> n;
	    vector<pair<int,int>>points;
	    for(int i = 0 ; i < n; i++){
	        int x, y;
	        cin >> x >> y;
	        points.push_back({x, y});
	    }

	    Solution ob;
	    double ans = ob.findOptimumCost(line, points, n);

	    cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}

// } Driver Code Ends