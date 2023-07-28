//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    bool dfs(int index, int n, vector<pair<int, int>> &locations, vector<vector<set<int>>> &boxes, vector<set<int>> &rows, vector<set<int>> &cols, int grid[N][N]) {
        if (index == n) return true;
        int x = locations[index].first, y = locations[index].second;
        for (int i=1; i<=9; i++) {
            if (rows[x].count(i)) continue;
            if (cols[y].count(i)) continue;
            if (boxes[x/3][y/3].count(i)) continue;
            rows[x].insert(i), cols[y].insert(i), boxes[x/3][y/3].insert(i);
            grid[x][y] = i;
            if (dfs(index+1, n, locations, boxes, rows, cols, grid)) return true;
            grid[x][y] = 0;
            rows[x].erase(i), cols[y].erase(i), boxes[x/3][y/3].erase(i);
        }
        return false;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        vector<vector<set<int>>> boxes(3, vector<set<int>>(3, set<int>()));
        vector<set<int>> rows(9, set<int>());
        vector<set<int>> cols(9, set<int>());
        vector<pair<int, int>> locations;
        for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
            rows[i].insert(grid[i][j]), cols[j].insert(grid[i][j]), boxes[i/3][j/3].insert(grid[i][j]);
            if (not grid[i][j]) locations.push_back({i, j});
        }
        return dfs(0, locations.size(), locations, boxes, rows, cols, grid);
    }
    void printGrid (int grid[N][N]) 
    {
        for (int i=0; i<N; i++) for (int j=0; j<N; j++) cout << grid[i][j] << ' ';
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends